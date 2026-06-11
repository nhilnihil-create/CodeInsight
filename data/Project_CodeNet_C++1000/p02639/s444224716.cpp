#include <cstdio>
using namespace std;

int x;

int main() {
    for (int i = 1; i <= 5; i++) {
        scanf("%d", &x);

        if (x != i) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}