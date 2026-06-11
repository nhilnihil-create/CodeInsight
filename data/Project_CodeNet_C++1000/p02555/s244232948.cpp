#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define repab(i,a,b) for(int i=a;i<=b;i++)
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define  printarr(v) for(auto x:v){cout<<x<<" "; }
#define debug1(a) cout<<#a<<" "<<(a)<<endl;
#define debug2(a,b) cout<<#a<<" "<<(a)<<" "<<#b<<" "<<(b)<<endl;
#define debug3(a,b,c) cout<<#a<<" "<<(a)<<" "<<#b<<" "<<(b)<<" "#c<<" "<<(c)<<endl;
typedef long double ld;
ll mod = 1e9 + 7;
ll dp[2005];
ll ok(ll val)
{
	if (val == 0)
	{
		return 1LL;
	}
	if (val == 1 || val == 2)
	{
		return 0LL;
	}
	if (val >= 3 && val <= 5)
	{
		return 1LL;
	}
	if (dp[val] != -1)
	{
		return dp[val];
	}
	ll ans = 0;
	for (ll i = 3; i <= val; i++)
	{
		if (val - i >= 0)
		{
			ans = (ans + ok(val - i)) % mod;
			ans = ans % mod;
		}
	}
	return dp[val] = ans;
}
void solve()
{
	ll n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	dp[0] = 1;
	cout << ok(n) << endl;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	t = 1;
	while (t--)
	{
		solve();

	}
}
