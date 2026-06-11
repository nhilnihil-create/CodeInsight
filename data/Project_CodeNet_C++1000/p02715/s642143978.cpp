#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
typedef vector<ll>vll;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
ll dp[N];
ll zabat(ll a)
{
    return ((a % M) + M) % M;
}
ll mul(ll a, ll b)
{
    return zabat(zabat(a) * zabat(b));
}
ll sub(ll a, ll b)
{
    return zabat(zabat(a) - zabat(b));
}
ll add(ll a, ll b)
{
    return zabat(zabat(a) + zabat(b));
}
ll fp(ll b, ll p)
{
    if(!p)      return 1;
    ll res = fp(b, p >> 1);
    res = mul(res, res);
    if(p & 1)   res = mul(res, b);
    return res;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k, ans = 0;
    cin >> n >> k;
    for(ll i = k;i > 0;--i)
    {
        dp[i] = fp(k / i, n);
        for(ll j = i + i;j <= k;j+=i)
            dp[i] = sub(dp[i], dp[j]);
    }
    for(int i = 1;i <= k;++i)
        ans = add(ans, mul(i, dp[i]));
    cout << ans;
    return 0;
}

