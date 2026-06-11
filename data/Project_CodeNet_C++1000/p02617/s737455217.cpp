#include <bits/stdc++.h>
using namespace std;
#define int long long
void read (int &x) {
    char ch = getchar(); x = 0;
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
} const int N = 2e5 + 10;
int n, ans, res;
signed main() {
    read (n);
    for (int i = 1; i <= n; ++i) res += i * (n - i + 1);
    for (int i = 1, u, v; i < n; ++i) {
        read (u), read (v);
        if (u > v) swap (u, v);
        res -= u * (n - v + 1);
    } return printf ("%lld\n", res), 0;
}
