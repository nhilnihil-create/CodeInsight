#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9 + 7, A = 4e3 + 2;
int add(ll x, ll y) {return (x + y) % mod;}
int mul(ll x, ll y) {return (x * y) % mod;}
ll fp (ll x, ll y)
{
    if (!y)
        return 1;
    ll acc = fp(x, y / 2);
    acc = mul(acc, acc);
    if (y & 1)
        acc = mul(acc, x);
    return acc;
}
int fact[A], inv[A];
void pre()
{
    fact[0] = inv[0] = 1;
    for (int i = 1; i < A; i++)
    {
        fact[i] = mul(fact[i - 1], i);
        inv[i] = fp(fact[i] , mod - 2);
    }
}
int ncr(int n, int r)
{
    return mul(fact[n], mul(inv[n - r], inv[r]));
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, k;
    cin >> n >> k;
    pre();
    for (int i = 1; i <= k; i++)
    {
        int ans = 0;
        if (i <= n - k + 1)
        {
            ans = ncr(k - 1, k - i); // blue blocks permuatations
            ans = mul(ans, ncr(n - k + 1, i)); // blue blocks permuatations with red
        }
        cout << ans << '\n';
    }
    return 0;
}