#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    if (n & (n - 1)) {
        puts("Yes");
        printf("%d %d\n", 1, 2);
        printf("%d %d\n", 2, 3);
        printf("%d %d\n", 3, n + 1);
        printf("%d %d\n", n + 1, n + 2);
        printf("%d %d\n", n + 2, n + 3);
        for (int i = 4; i < n; i += 2) {
            printf("%d %d\n", 1, i);
            printf("%d %d\n", i, n + i + 1);
            printf("%d %d\n", 1, i + 1);
            printf("%d %d\n", i + 1, n + i);
        }
        if (n % 2 == 0) {
            for (int i = 2; i < n; i++) {
                int j = n ^ i ^ 1;
                if (j >= 2 && j < n) {
                    return printf("%d %d\n%d %d\n", i, n, j, n + n), 0;
                }
            }
        }
    }
    else puts("No");
}