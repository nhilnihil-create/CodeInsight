#include <stdio.h>
using namespace std;

int a, b, c;

int main() {
    scanf("%d %d %d", &a, &b, &c);

    bool c1 = (a == b) && a != c;
    bool c2 = (b == c) && a != b;
    bool c3 = (a == c) && a != b;

    if (c1 || c2 || c3) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}