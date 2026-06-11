#include <stdio.h>

int main() {
    const int MAX = 9;

    for (int i = 1; i <= MAX; ++i) {
        for (int j = 1; j <= MAX; ++j) {
            int result = i * j;
            printf("%dx%d=%d\n", i, j, result);
        }
    }
}