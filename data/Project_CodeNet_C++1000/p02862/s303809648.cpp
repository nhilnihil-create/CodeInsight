#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1001001001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

const int MAX = 2000000;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main()
{
    COMinit();
    ll x, y;
    cin >> x >> y;
    if ((2 * x - y) % 3 == 0 && (2 * y - x) % 3 == 0)
    {
        ll a = (2 * x - y) / 3;
        ll b = (2 * y - x) / 3;
        cout << COM(a + b, a) << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}