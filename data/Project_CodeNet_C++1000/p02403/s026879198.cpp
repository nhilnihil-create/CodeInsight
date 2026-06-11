#include <iostream>
#include <cstdio>

using namespace std;

int
main(int argc, const char *argv[])
{
    int H, W;
    while (cin >> H >> W) {
        if (!H && !W) break;
        for (int i = 0; i != H; ++i) {
            for (int j = 0; j != W; ++j) putchar('#');
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}