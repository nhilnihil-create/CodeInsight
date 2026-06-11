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
template<class T> void chmax(T &a, const T b){ a = max(a, b); }
template<class T> void chmin(T &a, const T b){ a = min(a, b); }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n;
    cin >> n;
    vector<vector<pair<ll, ll>>> g(n);
    rep(i, n - 1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(make_pair(b, i));
        g[b].push_back(make_pair(a, i));
    }
    vector<ll> ans(n - 1, -1);
    rep(from, n) {
        set<ll> used;
        for(auto &x : g[from]) {
            ll to = x.first, idx = x.second;
            if (ans[idx] != -1) {
                used.insert(ans[idx]);
            }
        }
        ll val = 1;
        for(auto &x : g[from]) {
            ll to = x.first, idx = x.second;
            if (ans[idx] != -1) continue;
            while(used.count(val) > 0) {
                val++;
            }
            ans[idx] = val;
            val++;
        }
    }
    cout << *max_element(all(ans)) << endl;
    rep(i, n - 1) cout << ans[i] << endl;
    return 0;
}
