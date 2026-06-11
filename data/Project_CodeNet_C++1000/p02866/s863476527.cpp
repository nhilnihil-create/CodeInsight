#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

ll m = 998244353;
// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}



int main() {
    ll mod = 998244353;
    ll N;
    cin >> N;
    ll vec[100000];
    map<ll,ll> mp;
    for (ll i = 0;i<N;i++) {
        cin >> vec[i];
        mp[vec[i]]++;
    }
    bool ok = true;

    if (vec[0] != 0) ok = false;

    ll ans = 1;

    for (ll i = 1;i<N;i++) {
        ll a = mp[vec[i]-1];
        ans *= a;
        ans %= mod;
    }
    ans %= mod;
    if (ok) cout << ans << endl;
    else cout << 0 << endl;
}
