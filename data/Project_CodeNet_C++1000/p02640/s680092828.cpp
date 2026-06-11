#include <cstdio>
using namespace std;

int main() {
    int x, y;

    scanf("%d %d", &x, &y);

    int c, t;

    t = y / 2 - x;
    c = x - t;

    if (c + t == x && 2 * c + 4 * t == y && c >= 0 && t >= 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}