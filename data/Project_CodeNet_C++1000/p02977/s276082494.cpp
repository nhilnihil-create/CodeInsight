#include <bits/stdc++.h>
using namespace std;

int n;
void add(int u, int v) { printf("%d %d\n", u, v); }
int main() {
    scanf("%d", &n);
    if ((n & -n) == n) return puts("No"), 0;
    puts("Yes");
    add(1, 2), add(2, 3), add(3, 1 + n), add(1 + n, 2 + n), add(2 + n, 3 + n);
    for (int i = 4; i + 1 <= n; i += 2)
        add(1, i), add(i, i + 1), add(1, i + 1 + n), add(i + 1 + n, i + n);
    if (~n & 1) add(n, n + n - 1), add(n << 1, n ^ n - 1 ^ 1);
    return 0;
}