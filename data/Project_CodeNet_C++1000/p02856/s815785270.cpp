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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll m;
    cin >> m;
    vector<pair<ll, ll>> dc(m);
    rep(i, m) cin >> dc[i].first >> dc[i].second;
    ll sum = 0, ans = 0;
    rep(i, m) {
        sum += dc[i].first * dc[i].second;
        ans += dc[i].second;
    }
    cout << (ans + ((sum - 1) / 9) - 1) << endl;
    return 0;
}
