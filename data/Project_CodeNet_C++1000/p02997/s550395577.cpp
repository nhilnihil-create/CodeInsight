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
    ll n, k;
    cin >> n >> k;
    if (k > ((n - 1) * (n - 2) / 2)) {
        cout << -1 << endl;
        return 0;
    }
    vector<pair<ll, ll>> ans;
    reps(i, 1, n) ans.push_back(make_pair(0, i));
    ll remain = ((n - 1) * (n - 2) / 2) - k;
    reps(i, 1, n - 1) {
        if (remain == 0) break;
        reps(j, i + 1, n) {
            if (remain == 0) break;
            ans.push_back(make_pair(i, j));
            remain--;
        }
    }
    printf("%lld\n", sz(ans));
    rep(i, sz(ans)) printf("%lld %lld\n", ans[i].first + 1, ans[i].second + 1);
    return 0;
}
