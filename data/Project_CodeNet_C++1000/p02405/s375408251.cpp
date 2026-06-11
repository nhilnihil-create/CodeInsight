#include <iostream>
#include <utility>
#include <cstdio>

using namespace std;

int main(void) {

    while (true) {
        int H, W;
        cin >> H >> W;

        if (H == 0 || W == 0) { break; }

        for (int h = 0; h < H; ++h) {
            char c = h % 2 != 0 ? '#' : '.';
            for (int w = 0; w < W; ++w) {
                c = c == '#' ? '.' : '#';
                putchar(c);
            }
            putchar('\n');
        }

        putchar('\n');
    }

    return 0;
}