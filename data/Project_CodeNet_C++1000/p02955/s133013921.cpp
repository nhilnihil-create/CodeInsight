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

template<class T>
vector<T> get_divisor(T n) {
    vector<T> res;
    for (long long i = 1; (i * i) <= n; i++) {
        if (n % i != 0) continue;
        res.push_back(i);
        if ((i * i) != n) res.push_back(n / i);
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll ans = a[0];
    reps(i, 1, n) ans = __gcd(ans, a[i]);
    auto div = get_divisor(accumulate(all(a), 0LL));
    for(auto &x : div) {
        vector<ll> d(n);
        rep(i, n) d[i] = a[i] % x;
        sort(all(d));
        vector<ll> dp(n + 1, 0);
        rep(i, n) dp[i + 1] += dp[i] + d[i];
        bool f = false;
        reps(i, 1, n) {
            ll left = dp[i];
            ll right = (n - i) * x - (dp[n] - dp[i]);
            if ((left == right) && (k >= left)) {
                f = true;
                break;
            }
        }
        if (f) ans = max(ans, x);
    }
    cout << ans << endl;
    return 0;
}
