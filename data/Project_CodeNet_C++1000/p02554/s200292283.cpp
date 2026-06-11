#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
ll power(ll x, ll n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    ll y = power(x, n / 2) % MOD;
    return (y * y % MOD) * power(x, n % 2) % MOD;
}
int main()
{
    int n;
    cin >> n;
    cout << ((power(10, n) - power(9, n) - power(9, n) + power(8, n)) % MOD + MOD) % MOD << endl;
}
