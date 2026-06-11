#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod (ll)998244353
#define forn(i,k,n) for(ll i=k;i<n;i++)
#define v(ll) vector<ll>
#define vl(a,n,ll,k) vector<ll> a(n,k)
#define vll(a,n,m,ll,k) vector<vector<ll>> a(n,vector<ll>(m,k))
#define MAX 1000000
#define ed '\n'
#define pb push_back
#define mkp make_pair
#define lint ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int MOD = 1000000007;
int lcm(int a, int b)
{
  return(a*b/__gcd(a,b));
}
int main()
{
	lint;
	ll n;
	cin>>n;
	ll ans=lcm(n,360)/n;
	cout<<ans<<ed;
}