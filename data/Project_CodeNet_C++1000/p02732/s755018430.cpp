#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,sse")
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    int res = 0;
    for (int i = 0; i <= n; i++) {
        res += (cnt[i] * (cnt[i] - 1)) / 2;
    }
    for (int i = 0; i < n; i++) {
        cout << res - cnt[arr[i]] + 1 << '\n';
    }

    fflush(stdout);
    return 0;
}
