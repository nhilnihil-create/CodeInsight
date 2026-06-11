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
            for (int w = 0; w < W; ++w) {
                putchar('#');
            }
            putchar('\n');
        }
        putchar('\n');
    }

    return 0;
}