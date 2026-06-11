#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    const ll chars = 'z' - 'a' + 1;
    string s, t;
    cin >> s >> t;
    vector<vector<ll>> idx(chars);
    rep(i, len(s)) idx[s[i] - 'a'].push_back(i);
    ll lp = 0, cur = -1;
    rep(i, len(t)) {
        ll c = t[i] - 'a';
        if (sz(idx[c]) == 0) {
            cout << -1 << endl;
            return 0;
        }
        auto it = upper_bound(all(idx[c]), cur);
        if (it == idx[c].end()) {
            lp++;
            cur = *idx[c].begin();
        }
        else {
            cur = *it;
        }
    }
    cout << (len(s) * lp + cur + 1) << endl;
    return 0;
}
