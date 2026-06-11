#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T& a, T b)
{
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template <class T>
inline bool chmin(T& a, T b)
{
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------
ll N;

map<ll, ll> prime_factor(ll n)
{
    map<ll, ll> res;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res[i]++;
            n /= i;
        }
    }
    if (n != 1) {
        res[n]++;
    }
    return res;
}

ll divs[2010101];

int main()
{
    cin >> N;
    ll ans = 1;

    auto res = prime_factor(N - 1);
    for (auto e : res) {
        auto k = e.first;
        auto v = e.second;
        ans *= v + 1;
    }
    ans--;

    ll cnt = 0;
    for (ll i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            divs[cnt] = i;
            cnt++;
        }
    }

    for (int i = 0; i < cnt; i++) {
        ll d = divs[i];
        ll nn = N;
        while (nn % d == 0) {
            nn /= d;
        }
        if ((nn - 1) % d == 0) {
            ans++;
        }
    }

    ans++;

    cout << ans << endl;
}