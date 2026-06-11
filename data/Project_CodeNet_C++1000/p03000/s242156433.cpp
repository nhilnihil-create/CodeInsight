#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,sse")
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> kek(n);
    int now = 0;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        cin >> kek[i];
        now += kek[i];
        if (now <= x) {
            cnt++;
        }
    }
    cout << cnt << '\n';

    fflush(stdout);
    return 0;
}
