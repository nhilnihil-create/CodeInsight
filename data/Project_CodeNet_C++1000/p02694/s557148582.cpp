#include <bits/stdc++.h>
#define int unsigned long long
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,sse")
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x;
    int bal = 100;
    cin >> x;
    int cnt = 0;
    while (bal < x) {
        bal += (bal / 100);
        cnt++;
    }
    cout << cnt << '\n';

    fflush(stdout);
    return 0;
}
