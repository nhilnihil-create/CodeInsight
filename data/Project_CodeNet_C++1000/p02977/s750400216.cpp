#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n;

void write(int x, int to) {
    if (x % 2) {
        x += n;
    }
    printf("%d %d\n", x, to);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    int x = 1;
    while (2 * x <= n) {
        x *= 2;
    }
    if (x == n) {
        puts("No");
        return 0;
    }
    puts("Yes");
    for (int i = 2; i < n; i += 2) {
        printf("1 %d\n", i);
        printf("%d %d\n", i, i + 1);
        printf("1 %d\n", n + i + 1);
        printf("%d %d\n", n + i + 1, n + i);
    }
    printf("3 %d\n", n + 1);
    if (n % 2 == 0) {
        int y = n ^ x ^ 1;
        write(x, n);
        write(y, 2 * n);
    }
    return 0;
}
