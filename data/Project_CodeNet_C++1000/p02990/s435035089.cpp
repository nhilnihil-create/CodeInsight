#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
const int N = 5005, M = 1e9 + 7;
ll fact[N];
ll mul(ll a, ll b)
{
    a %= M;
    b %= M;
    return (a * b) % M;
}
void pre()
{
    fact[0] = 1;
    for(int i = 1;i < N;++i)
        fact[i] = mul(fact[i - 1], i);
}
ll fp(ll b, ll p)
{
    if(!p)      return 1;
    ll res = fp(b, p >> 1);
    res = mul(res, res);
    if(p & 1)   res = mul(res, b);
    return res;
}
ll inv(ll n)
{
    return fp(n, M - 2);
}
ll ncr(ll n, ll r)
{
    return mul(fact[n], mul(inv(fact[r]), inv(fact[n - r])));
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    pre();
    ll n, k;
    cin >> n >> k;
    for(int i = 1;i <= k;++i)
    {
        if(i <= n - k + 1)  cout << mul(ncr(k - 1, i - 1), ncr(n - k + 1, i));
        else                cout << 0;
        cout << '\n';
    }
    return 0;
}
