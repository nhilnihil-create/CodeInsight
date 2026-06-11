#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<n; i++)

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<pair<ll, int>> p(n);
    rep(i, n) {
        cin >> p[i].first;
        p[i].second = i;
    }

    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());

    set<ll> bigger;
    bigger.insert(-1);
    bigger.insert(-2);
    bigger.insert(n);
    bigger.insert(n+1);

    ll ans = 0;

    rep(i, n) {
        ll q = p[i].first;
        int idx = p[i].second;

        auto r_idx = *bigger.lower_bound(idx);
        auto r_idx2 = *bigger.upper_bound(r_idx);
        auto l_idx = *(--bigger.lower_bound(idx));
        auto l_idx2 = *(--bigger.lower_bound(l_idx));
        // cout << q << " " << idx << endl;
        // cout << l_idx2 << " " << l_idx << " " << r_idx << " " << r_idx2 << endl;
        // cout << endl;

        if (l_idx != -1) {
            ans += (l_idx-l_idx2)*(r_idx-idx)*q;
        }
        if (r_idx != n ) {
            ans += (idx-l_idx)*(r_idx2-r_idx)*q;
        }
        bigger.insert(idx);
    }

    cout << ans << endl;
}