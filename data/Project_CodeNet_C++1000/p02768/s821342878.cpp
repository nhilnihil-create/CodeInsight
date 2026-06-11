#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repk(i, k, n) for (int i = k; i < n; i++)
#define MOD 1000000007
#define INF 1e9
#define PIE 3.14159265358979323

template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T GCD(T a, T b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
template <class T>
inline T LCM(T a, T b) {
    return (a * b) / GCD(a, b);
}

ll modpow(ll a, ll n) {
    a %= MOD;
    if (n == 0)
        return 1;
    if (n == 1)
        return a % MOD;
    if (n % 2)
        return a * modpow(a, n - 1) % MOD;
    else
        return (modpow(a, n / 2) * modpow(a, n / 2)) % MOD;
}

ll culc(ll a, ll n) {
    ll up = 1;
    ll down = 1;
    for (ll i = n - a + 1; i <= n; i++) {
        up *= i % MOD;
        up %= MOD;
    }
    for (ll i = 1; i <= a; i++) {
        down *= i % MOD;
        down %= MOD;
    }
    down = modpow(down, MOD - 2);
    return up * down % MOD;
}

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = modpow(2, n) - 1 - culc(a, n) - culc(b, n);
    while (ans < 0) {
        ans += MOD;
    }
    cout << ans << endl;
    return 0;
}