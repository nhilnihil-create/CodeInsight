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
    queue<ll> q;
    q.push(0);
    vector<ll> ans(n - 1, -1);
    while(!q.empty()) {
        ll v = q.front(); q.pop();
        set<ll> used;
        for(auto u : g[v]) {
            if (ans[u.second] != -1) {
                used.insert(ans[u.second]);
            }
        }
        ll cv = 0;
        for(auto u : g[v]) {
            if (ans[u.second] == -1) {
                while(used.count(cv) > 0) {
                    cv++;
                }
                ans[u.second] = cv;
                used.insert(cv);
                q.push(u.first);
            }
        }
    }
    cout << (*max_element(all(ans)) + 1) << endl;
    rep(i, n - 1) cout << (ans[i] + 1) << endl;
    return 0;
}
