#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <set>
#include <map>
#include <list>
#include <cstdlib>
#include <queue>
#include <stack>

using namespace std;

#define mod 1000000007
#define PI 3.1415926535897932
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, j, n) for (int i = j; i < n; i++)
#define repi(i, n) for (int i = 0; i <= n; i++)
#define repie(i, j, n) for (int i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl
#define P pair<int, int>
#define fi first
#define se second

typedef long long ll;

long long modinv(long long a, long long m)
{
    long long b = m, u = 1, v = 0;
    while (b)
    {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

ll sumf(ll n) {
    ll r = n*(n+1);
    r %= mod;

    return r*modinv(2, mod)%mod;
}

ll fnc(ll k, ll n) {
    ll s = sumf(k-1);
    ll end = sumf(n)-sumf(n - k);
    if(end < 0) {
        end += mod;
    }

    ll r = end - s;
    if(r < 0) {
        r += mod;
    }

    return r;
}

void solve1()
{
    int n, k; cin >> n >> k;
    ll sum = 1;
    for(int i = k; i < n + 1; i++) {
        sum += fnc(i, n) + 1;
        sum %= mod;
    }

    cout << sum << endl;
}

int main()
{
    solve1();
}
