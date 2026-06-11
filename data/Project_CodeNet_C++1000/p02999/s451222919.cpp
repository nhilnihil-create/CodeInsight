#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,sse")
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, a;
    cin >> x >> a;
    if (x < a) {
        cout << 0;
    } else {
        cout << 10;
    }

    fflush(stdout);
    return 0;
}
