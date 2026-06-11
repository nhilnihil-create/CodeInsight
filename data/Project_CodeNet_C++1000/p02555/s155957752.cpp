//code by parshuram_84
#include <bits/stdc++.h>
#define floop(i,a,n) for (int i=a;i<n;i++)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);cout.precision(dbl::max_digits10);
#define pb push_back
#define mod 1000000007 //998244353
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vvl vector<vector<long long> >
#define vp vector<pair<long long,long long>>
#define vpp vector<pair<pair<long long,long long>,long long>>
#define mp make_pair
#define all(c) c.begin(),c.end()
#define tr(container, it) \
for(typeof(container.begin()) it = container.begin();it != container.end(); it++)
typedef std::numeric_limits< double > dbl;
using namespace std;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll ncr(ll n,ll r) { ll p=1,k=1; if(n-r<r) r=n-r; if(r!=0) {while(r!=0) {p*=n; k*=r; ll temp=gcd(p,k); p/=temp; k/=temp; n--; r--;} } else p=1; return p;}
ll pm(ll x,ll n) {ll result=1; while(n>0){if(n%2==1) result=((result%mod)*(x%mod))%mod; x=((x%mod)*(x%mod))%mod; n/=2;} return result;}
ll p(ll x,ll n) {ll result=1; while(n>0){if(n%2==1) result=result*x; x=x*x; n/=2;} return result;}
ll factorial[300000+1];
void fact(ll n) { factorial[0]=1; factorial[1]=1; floop(i,2,n+1) factorial[i] = (i * factorial[i-1]%mod) % mod; }


int32_t main() {
	IOS;
	ll t,i,j,k,n,x,y,z;
	string s;
	cin>>n;z=0;
	fact(2000);
	for(i=1;i<=n/3;i++)
	{
		x=n-3*i+i-1;
		y=(factorial[x]*pm(factorial[i-1],mod-2))%mod;
		y=(y*pm(factorial[x-i+1],mod-2))%mod;
		z+=y;
		z%=mod;
	}
	cout<<z;
	return 0;
}