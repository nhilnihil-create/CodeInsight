#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<ii> vii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define fr(be, en) for(int i = be; i <= en; i++) 
ll mod = 1e9 + 7;
ll power(ll a, ll b)
{
	if(b == 0) return 1;
	ll ans = power(a, b/2);
	ans = (ans*ans)%mod;
	if(b%2) ans*=a;
	return ans%mod;
}
ll mul(ll a,ll n, ll mod)
{
	ll ret;
	if(n==0) return 0;
	ret = mul(a,n/2, mod);
	ret = (ret+ret)%mod;
	if(n%2)	ret=(ret+a)%mod;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	ll n, k;
	cin >> n >> k;
	vi ways(1e5 + 1, 0);
	ll ans = 0;
	for(int i = k; i >= 1; i--)
	{
		ll poss = k/i;
		ll poss_sub  = power(poss, n);
		for(int j = i; j <= k; j+= i) 
		{
			poss_sub -= ways[j];
			if(poss_sub < 0) poss_sub += mod;
		}
		ways[i] = poss_sub;
		ans = (ans + ways[i]*i)%mod;
	}
	cout << ans;
}