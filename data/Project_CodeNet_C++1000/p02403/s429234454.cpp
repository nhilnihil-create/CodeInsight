#include <cstdio>

using namespace std;

int main() {
    while (true) {
        size_t H, W;
        scanf("%zu %zu", &H, &W);

        if (!W && !H)
            return 0;

        for (size_t i=0; i<H; ++i) {
            for (size_t j=0; j<W; ++j)
                printf("#");

            printf("\n");
        }

        printf("\n");
    }
}