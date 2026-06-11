#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <list>
#include <numeric>
#include <stack>
#include <iomanip>
#include <random>
#include <complex>
#include <functional>
#include <tuple>
#include <new>

using namespace std;

#define EPS (1e-9)
#define INF (1e9)
#define MOD (ll)(1e9 + 7)
#define PI (acos(-1))
#define REP(i,a,n) for(int i=a;i<n;i++)
#define rep(i, n) REP(i,0,n)
#define allof(a) (a).begin(), (a).end()

#define Yes(q) ((q) ? "Yes" : "No")
#define YES(q) ((q) ? "YES" : "NO")
#define Possible(q) ((q) ? "Possible" : "Impossible")
#define POSSIBLE(q) ((q) ? "POSSIBLE" ; "IMPOSSIBLE")

using ll = long long int;

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll beki(ll a, ll b) {
    ll tmp = 1;
    rep(i, b) tmp *= a;
    return tmp;
}

ll modPow(ll x, ll a) {
    if (a == 1) return x;
    if (a % 2) return (x * modPow(x, a - 1)) % MOD;
    ll t = modPow(x, a / 2);
    return ((t % MOD) * (t % MOD)) % MOD;
}

ll modInv(ll x) {
    return modPow(x, MOD - 2);
}

ll N;
vector<ll> A(300010);
vector<ll> bit_cnt(110, 0);
ll ans = 0;

int main() {
    cin >> N;
    rep(i, N) cin >> A[i];
    rep(i, N) {
        rep(j, 60) {
            bit_cnt[j] += (A[i] >> j) & 1;
        }
    }

    rep(i, 60) {
        ans += (((bit_cnt[i] * (N - bit_cnt[i])) % MOD) * (beki(2, i) % MOD)) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}