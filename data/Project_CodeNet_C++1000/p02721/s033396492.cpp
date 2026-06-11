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
    ll n, k, c;
    string s;
    cin >> n >> k >> c >> s;
    vector<ll> ldp(n + 2, 0), rdp(n + 2, 0);
    ll idx = -c - 1;
    rep(i, n) {
        ldp[i + 1] = ldp[i];
        if ((s[i] == 'o') && (idx < (i - c))) {
            ldp[i + 1]++;
            idx = i;
        }
    }
    idx = n + c + 1;
    rrep(i, n) {
        rdp[i + 1] = rdp[i + 2];
        if ((s[i] == 'o') && (idx > (i + c))) {
            rdp[i + 1]++;
            idx = i;
        }
    }
    ldp[n + 1] = ldp[n];
    rdp[0] = rdp[1];
    vector<ll> ans;
    rep(i, n) {
        if ((ldp[i] + rdp[i + 2]) < k) ans.push_back(i + 1);
    }
    rep(i, sz(ans)) printf("%lld\n", ans[i]);
    return 0;
}
