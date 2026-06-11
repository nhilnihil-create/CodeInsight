#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    string s, t;
    cin >> s >> t;
    
    map<char, vi> m;
    rep(i, sz(s)) m[s[i]].pb(i);

    int runs = 0, i = -1;
    rep(j, sz(t)) {
        if (!m.count(t[j])) {
            cout << -1;
            return 0;
        }

        auto it = upper_bound(all(m[t[j]]), i);
        if (it == m[t[j]].end()) runs++, it = m[t[j]].begin();
        i = *it;
    }
    cout << (ll)runs * sz(s) + i + 1;

    return 0;
}
