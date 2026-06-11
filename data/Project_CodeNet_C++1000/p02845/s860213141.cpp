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
    const ll mod = 1e9 + 7;
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> cnt(3, 0);
    ll ans = 1;
    rep(i, n) {
        ll pat = 0;
        rep(j, 3) {
            if (cnt[j] == a[i]) {
                if (pat == 0) cnt[j]++;
                pat++;
            }
        }
        ans = (ans * pat) % mod;
    }
    cout << ans << endl;
    return 0;
}
