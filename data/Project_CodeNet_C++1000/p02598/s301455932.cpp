#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    ll ok = 2e9, ng = 0;
    auto check = [&](ll x) -> bool {
        int cnt = 0;
        rep(i, n) {
            cnt += (a[i] - 1) / x;
        }

        return cnt <= k;
    };
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }

    cout << ok << endl;

    return 0;
}