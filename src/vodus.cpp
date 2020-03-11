#include <cassert>
#include <cstdio>
#include <cstdint>
#include <cmath>

#include <functional>

#include <ft2build.h>
#include FT_FREETYPE_H
#include <gif_lib.h>
#include <png.h>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavutil/opt.h>
#include <libavutil/imgutils.h>
}

void print1(FILE *stream, char c)
{
    fputc(c, stream);
}

void print1(FILE *stream, int x)
{
    fprintf(stream, "%d", x);
}

void print1(FILE *stream, long unsigned int x)
{
    fprintf(stream, "%lu", x);
}

void print1(FILE *stream, uint32_t x)
{
    fprintf(stream, "%u", x);
}

void print1(FILE *stream, const char *cstr)
{
    fputs(cstr, stream);
}

struct Pad
{
    size_t n;
    char c;
};

void print1(FILE *stream, Pad pad)
{
    for (size_t i = 0; i < pad.n; ++i) {
        fputc(pad.c, stream);
    }
}

template <typename... T>
void print([[maybe_unused]] FILE *stream, T... args)
{
    (print1(stream, args), ...);
}

template <typename... T>
void println(FILE *stream, T... args)
{
    print(stream, args...);
    fputc('\n', stream);
}

// https://en.wikipedia.org/wiki/Single_Compilation_Unit
#include "./vodus_image32.cpp"
#include "./vodus_main.cpp"
