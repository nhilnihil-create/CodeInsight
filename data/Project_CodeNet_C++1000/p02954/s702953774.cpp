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
    string s;
    cin >> s;
    vector<ll> idx;
    ll n = len(s);
    rep(i, n - 1) {
        if ((s[i] == 'R') && (s[i + 1] == 'L')) {
            idx.push_back(i);
        }
    }
    vector<ll> ans(n, 0);
    rep(i, n) {
        auto it = lower_bound(all(idx), i);
        if (s[i] == 'L') it--;
        ll diff = abs(i - *it);
        if (diff % 2 == 0) {
            ans[*it]++;
        }
        else {
            ans[*it + 1]++;
        }
    }
    rep(i, n) printf("%lld%s", ans[i], (i == (n - 1)) ? "\n" : " ");
    return 0;
}
