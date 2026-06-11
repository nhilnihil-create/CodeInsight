#include <bits/stdc++.h>
using namespace std;
void read (int &x) {
    char ch = getchar(); int f = 0; x = 0;
    while (!isdigit(ch)) { if (ch == '-') f = 1; ch = getchar(); }
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); if (f) x = -x;
} const int N = 2e5 + 10;
int n, a; long long res; map<int, int> c;
signed main() {
    read (n);
    for (int i = 1; i <= n; ++i)
        read (a), res += c[i - a], ++c[i + a];
    return printf ("%lld\n", res), 0;
}
