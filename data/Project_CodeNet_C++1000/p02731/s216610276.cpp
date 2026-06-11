#include <bits/stdc++.h>
#define int long long
#define double long double
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,sse")
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    double x;
    cin >> x;
    double t = x / 3.0;
    cout << fixed << setprecision(10) << t * t * t << '\n';

    fflush(stdout);
    return 0;
}
