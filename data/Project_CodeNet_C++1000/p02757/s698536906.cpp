#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
using ll = long long;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

ll pow_mod(ll n, ll k, ll mod) {
    if(k == 0) {
        return 1;
    } else if(k % 2 == 1) {
        return pow_mod(n, k - 1, mod) * n % mod;
    } else {
        ll t = pow_mod(n, k / 2, mod);
        return t * t % mod;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) {
        a[i] = (ll)(s[i] - '0');
    }
    reverse(ALL(a));
    vector<int> sum(n + 1, 0);
    for(ll i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + a[i] * pow_mod(10, i, p) % p;
        sum[i + 1] %= p;
    }
    map<ll, ll> mp;
    for(ll i = 0; i < n + 1; i++) {
        // cout << sum[i] << " ";
        mp[sum[i]]++;
    }
    // cout << endl;
    ll ans = 0;
    if(p == 2 || p == 5) {
        for(int i = 0; i < n; i++) {
            if(a[i] % p == 0) {
                ans += n - i;
            }
        }
        cout << ans << endl;
        return 0;
    }
    for(const auto &p : mp) {
        ans += (p.second - 1) * p.second / 2;
    }
    cout << ans << endl;
}