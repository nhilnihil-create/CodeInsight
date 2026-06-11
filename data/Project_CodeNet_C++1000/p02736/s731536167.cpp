#include <bits/stdc++.h>
using namespace std;
int read();
int n;
char s[1000006];
int a[1000006];
void calc() {
    for (int i = 1; i < n; ++i) a[i] = abs(a[i] - a[i + 1]);
    --n;
}
int main() {
    n = read(), scanf("%s", s + 1);
    for (int i = 1; i <= n; ++i) a[i] = s[i] - '0';
    if (n == 2) return calc(), printf("%d\n", a[1]), 0;
    calc(), calc();
    int res = 0;
    for (int i = 1; i <= n; ++i) res ^= ((n - 1 | i - 1) == n - 1) * (a[i] & 1);
    if (res == 1) return puts("1"), 0;
    for (int i = 1; i <= n; ++i)
        if (a[i] == 1) return puts("0"), 0;
    res = 0;
    for (int i = 1; i <= n; ++i)
        res ^= ((n - 1 | i - 1) == n - 1) * (a[i] >> 1 & 1);
    printf("%d\n", res << 1);
    return 0;
}

int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
