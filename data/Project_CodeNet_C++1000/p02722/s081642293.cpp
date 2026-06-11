#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <deque>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i, up) for (ll i = 0; i < up; ++i)
#define repp(i, up) for (ll i = 0; i <= up; ++i)
#define rrep(i, lo, up) for (ll i = lo; i < up; ++i)
#define rrepp(i, lo, up) for (ll i = lo; i <= up; ++i)

#define rdi(i) ll i; scanf("%lld", &i)
#define rds(s) string s; cin >> s
#define rdc(c) char c; cin >> c

#define INF 10000000000
#define MOD 1000000007

ll gcd(ll a, ll b)
{
    if (a < b) {
        return gcd(b, a);
    }
    ll r;
    while (r = a % b) {
        a = b;
        b = r;
    }
    return b;
}

int main()
{
    ll n;
    cin >> n;
    ll result = 0;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i != 0) {
            continue;
        }
        for (ll j = i; j <= n; j *= i) {
            if (n % j != 0) {
                break;
            }
            if ((n / j) % i == 1) {
                ++result;
                break;
            }
        }
        ll ii = n / i;
        if (ii == i) {
            continue;
        }
        for (ll j = ii; j <= n; j *= ii) {
            if (n % j != 0) {
                break;
            }
            if ((n / j) % ii == 1) {
                ++result;
                break;
            }
        }
    }
    ++result;

    for (ll i = 2; i * i <= n - 1; ++i) {
        if ((n - 1) % i != 0) {
            continue;
        }
        ++result;
        ll ii = (n - 1) / i;
        if (ii == i) {
            continue;
        }
        ++result;
    }
    if (n > 2) {
        ++result;
    }
    cout << result << endl;
    return 0;
}