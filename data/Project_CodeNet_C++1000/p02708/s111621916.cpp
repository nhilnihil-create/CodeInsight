#include <bits/stdc++.h>
#define PREP(i, s, x) for(ll i = (s); i < (x); i++)
#define MREP(i, s, x) for(ll i = (s); i >= (x); i--)
#define REP(i, x) PREP(i, 0, x)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

// variable -------------------------------------------

constexpr ll INF = (1ll << 60);
constexpr ll MOD = 1000000007ll;

// structure ------------------------------------------

// function -------------------------------------------

// main -----------------------------------------------

int main() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    ll sum_min = 0, sum_max = 0;
    PREP(i, k, n+2){
        sum_min = i * (i-1) / 2;
        sum_max = n * i - sum_min;
        ans += (sum_max - sum_min + 1) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
