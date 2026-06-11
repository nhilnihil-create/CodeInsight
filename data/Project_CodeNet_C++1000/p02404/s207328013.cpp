#include <iostream>
#include <utility>
#include <cstdio>

using namespace std;

int main(void) {

    while (true) {
        int H, W;
        cin >> H >> W;

        if (H == 0 || W == 0) { break; }

        for (int w = 0; w < W; ++w) { putchar('#'); }
        putchar('\n');

        for (int h = 1; h < H - 1; ++h) {
            putchar('#');
            for (int w = 1; w < W - 1; ++w) {
                putchar('.');
            }
            putchar('#');
            putchar('\n');
        }

        for (int w = 0; w < W; ++w) { putchar('#'); }
        putchar('\n');
        putchar('\n');
    }

    return 0;
}