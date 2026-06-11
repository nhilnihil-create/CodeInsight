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

#define MOD 1000000007
#define pi 3.1415926535897932
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, j, n) for (int i = j; i < n; i++)
#define repi(i, n) for (int i = 0; i <= n; i++)
#define repie(i, j, n) for (int i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl
#define P pair<int, int>
#define fi first
#define se second
const int MAX = 510000;
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

// 二項係数計算
long long COM(ll n, ll k) {
    ll res = 1;
    for(int i = 0; i < k; i++) {
        res *= n - i;
        res %= MOD;
        res = res*modinv(i+1, MOD)%MOD;
    }

    return res%MOD;
}

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

void solve1() {
    int n, a, b; cin >> n >> a >> b;

    ll sum = modpow(2, n, MOD);
    sum --;
    if(sum < 0) {
        sum += MOD;
    }

    sum -= COM(n, a);
    if (sum < 0)
    {
        sum += MOD;
    }

    sum -= COM(n, b);
    if (sum < 0)
    {
        sum += MOD;
    }

    cout << sum << endl;
}

int main()
{
    solve1();
}
