#include <bits/stdc++.h>
#define N 100010
#define pb push_back
#define fi first
#define se second
#define si size()
#define ll long long
#define mp make_pair
#define iter ::iterator
#define all(v) v.begin(), v.end()
#define pp pop_back
#define mapiter map<int, int>::iterator
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forn1(i, n) for(int i = 1; i <= n; ++i)
#define forr(i, n)	for(int i = n - 1; i >= 0; --i)
#define forr1(i, n)	for(int i = n; i >= 1; --i)
#define form(l, r, i)	for(int i = l; i <= r; ++i)
#define forv(r, l, i)	for(int i = r; i >= l; --i)
#define r0 return 0
#define barnarnar ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lld long double
#define elif else if
 
const int inf = 1e9 + 7;
const lld EPS = 0.00000001;
const ll modwdop = 998244353ll;
 
ll pp = 13337ll;
ll modw = 1e9 + 7;
 
using namespace std;

ll dp[N];
ll n, k;

ll binpow(ll a, ll n)
{
	if(n == 0)	return 1ll;
	if(n % 2 == 1)	return (binpow(a, n - 1) * a) % modw;
	else
	{
		ll b = binpow(a, n / 2);
		return (b * b) % modw;
	}
}

ll rec(ll x)
{
    if(dp[x])	return dp[x];
    dp[x] = binpow(k / x, n);
    for(int i = x * 2; i <= k;i += x)
    {
    	dp[x] -= rec(i);
		while(dp[x] < 0ll)	dp[x] += modw;
		dp[x] %= modw; 
	}
    return dp[x];
}

int main()
{
	barnarnar
	cin >> n >> k;
	ll ans = 0;
	forr1(i, k)
	{
		ans += (i * rec(i)) % modw;
		ans %= modw;
	}
	cout << ans;
}