#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using P = pair<ll, ll>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T, typename K> using ump = unordered_map<T, K>;
const ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll e5 = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = ll(n - 1); i >= 0; i--)
#define each(i, mp) for(auto& i:mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()

template<class T>
ostream &operator<<(ostream &out, const vector<T> &list) {
    ll n = list.size();
    rep(i, n) out << list[i] << ' ';
    return out;
}

template<class T>
istream &operator>>(istream &in, vector<T> &list) {
    ll n = list.size();
    rep(i, n) in >> list[i];
    return in;
}

template<class T>
ostream &operator<<(ostream &out, const vector<vector<T>> &list) {
    ll n = list.size();
    rep(i, n) out << list[i] << '\n';
    return out;
}

/* ------------- ANSWER ------------- */
/* ---------------------------------- */

void solve() {
    ll n, k;
    cin >> n >> k;
    ll r, s, p;
    cin >> r >> s >> p;
    string t;
    cin >> t;
    const ll RR = 0, SS = 1, PP = 2;

    ll ans = 0;
    for (ll i = 0; i < k; ++i) {
        vector<vector<ll>> dp(n / k + 10, vector<ll>(3));
        ll tmp = 0;
        for (ll j = i; j < n; j += k) {
            ll idx = j / k;
            rep(now, 3) {
                rep(prev, 3) {
                    if (idx > 0 && now == prev) continue;
                    if (t[j] == 'r') {
                        if (now == PP) {
                            dp[idx + 1][now] = max(dp[idx + 1][now], dp[idx][prev] + p);
                        } else {
                            dp[idx + 1][now] = max(dp[idx + 1][now], dp[idx][prev]);
                        }
                    } else if (t[j] == 's') {
                        if (now == RR) {
                            dp[idx + 1][now] = max(dp[idx + 1][now], dp[idx][prev] + r);
                        } else {
                            dp[idx + 1][now] = max(dp[idx + 1][now], dp[idx][prev]);
                        }
                    } else {
                        if (now == SS) {
                            dp[idx + 1][now] = max(dp[idx + 1][now], dp[idx][prev] + s);
                        } else {
                            dp[idx + 1][now] = max(dp[idx + 1][now], dp[idx][prev]);
                        }
                    }
                }
                tmp = max(tmp, dp[idx + 1][now]);
            }
        }
        ans += tmp;
    }
    cout << ans << '\n';
}

int main() {
#ifdef MY_DEBUG
    while (true) {
#endif
        solve();
#ifdef MY_DEBUG
    }
#endif
    return 0;
}