#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

ll n;
set<string> ans;

void dfs(vector<ll> &vs) {
    if (sz(vs) == n) {
        string tmp = "";
        rep(i, n) tmp += (char)(vs[i] + 'a');
        ans.insert(tmp);
        return;
    }
    ll mv = *max_element(all(vs));
    rep(i, mv + 2) {
        vs.push_back(i);
        dfs(vs);
        vs.pop_back();
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    cin >> n;
    vector<ll> vs(1, 0);
    dfs(vs);
    for(auto x : ans) printf("%s\n", x.c_str());
    return 0;
}
