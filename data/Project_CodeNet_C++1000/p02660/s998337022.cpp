#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define INIT    \
    cin.tie(0); \
    ios::sync_with_stdio(false);

template <class T>
inline bool chmax(T& a, T b) {
    return a = (a < b) ? b : a;
}
template <class T>
inline bool chmin(T& a, T b) {
    return a = (a > b) ? b : a;
}

ll const INF = 1LL << 60;
ll const MOD = 1000000007;

// 素因数分解 O(√n)
map<ll, ll> prime_factor(ll n) {
    map<ll, ll> res;

    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ++res[i];
            n /= i;
        }
    }

    if (n != 1) res[n] = 1;

    return res;
}

int main() {
    INIT;

    ll N;
    cin >> N;

    map<ll, ll> primes = prime_factor(N);

    // for (auto elem : primes) {
    //     cout << elem.first << " " << elem.second << endl;
    // }

    map<ll, ll> cnts;
    ll ans = 0;
    for (auto elem : primes) {
        while (elem.second > 0) {
            if (elem.second < cnts[elem.first] + 1) break;

            N /= pow(elem.second, cnts[elem.first] + 1);
            ans++;
            cnts[elem.first]++;
            elem.second -= cnts[elem.first];
        }
    }

    cout << ans << endl;

    return 0;
}