#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int H, W;
    while (true) {
        scanf("%d %d", &H, &W);
        if (H == 0 && W == 0) break;

        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                if (h == 0 || h == H -1) {
                    printf("#");
                } else if (w == 0 || w == W -1) {
                    printf("#");
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }

        printf("\n");
    }
}