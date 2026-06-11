#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9 + 7, A = 2e3 + 2;
int mul(ll x, ll y) {return (x * y) % mod;}
int add(ll x, ll y) {return ((x + y) % mod + mod) % mod;}
int fp (ll x, ll y)
{
    if (!y) return 1;
    int acc = fp(x, y / 2);
    acc = mul(acc, acc);
    if (y & 1) acc = mul(acc, x);
    return acc;
}
int ncr(int n, int r)
{
    int ans = 1, fact = 1;
    for (int i = n - r + 1; i <= n; i++)
        ans = mul(ans, i);
    for (int i = 2; i <= r; i++)
        fact = mul(fact, i);
    return mul(ans, fp(fact, mod - 2));
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    cout << add(fp(2, n), -add(1, add(ncr(n, a), ncr(n, b))));
    return 0;
}