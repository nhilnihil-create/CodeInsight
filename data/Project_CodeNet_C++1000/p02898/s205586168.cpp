#include <bits/stdc++.h>

//#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x >= k) res++;
    }
    cout << res << '\n';
}
/*

 */