#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,sse")
using namespace std;

int calc(int a, int b, int x) {
    return ((a * x) / b) - (a * (x / b));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, n;
    cin >> a >> b >> n;
    cout << calc(a, b, min(n, b - 1)) << '\n';

    fflush(stdout);
    return 0;
}
