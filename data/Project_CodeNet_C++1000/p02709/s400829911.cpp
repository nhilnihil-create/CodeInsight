#include <bits/stdc++.h>

#define gcd(m,n) __gcd(m,n)
#define lcm(m,n) m*(n/gcd(m,n))
#define fast std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pi acos(-1.0)
#define endl '\n'
#define MOD 1000000007
#define ull unsigned long long
#define ll long long
#define ld long double
#define pb push_back
#define dbg(x) cout << #x << "  " << x << endl;

ll power(ll base, ll exp) 
{ll res=1;while(exp>0) {if(exp%2==1) res=(res*base);base=(base*base);exp/=2;}return res;}
ll mod(ll a, ll b) {return (a % b + b) % b;}

using namespace std;
pair<ll,ll>arr[2003];
ll dp[2003][2003];   
ll n,x;
ll solve(ll l, ll r)
{
	if (l > r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    
    ll idx = n - (r - l + 1) + 1;
    ll a =  (ll)abs(arr[idx].second - l) * arr[idx].first + solve(l+1,r);
    ll b = (ll)abs(arr[idx].second - r) * arr[idx].first + solve(l,r-1);
    
    return dp[l][r] = max(a,b);
} 
int main() 
{	
	fast;
	 cin>>n;
	for(ll i = 1; i <= n; i++)
	{
		cin>>x;
		arr[i] = {x,i};
	}
	sort(arr+1,arr+n+1);
	reverse(arr+1,arr+n+1);
	memset(dp,-1,sizeof(dp));
	cout << solve(1,n) << endl;
	return 0;
}