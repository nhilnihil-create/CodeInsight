//----------BHAVIK DIWANI(PICT_COMP)---------------
#include<bits/stdc++.h>
#include<stdlib.h>
#include<stdio.h>
#define test ll t; cin>>t; while(t--)
#define FOR(p,n) for(ll i=p;i<(ll)n;i++)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define ll long long
#define int long long
#define ull unsigned long long
#define MAX 1000005
#define pb push_back
#define mkp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define endl '\n'
#define vs vector<string>
#define mii map<int,int>
#define msi map<string,int>
#define vpii vector< pair<int, int > >
#define vpsi vector< pair< string ,int > >
#define forci(p,q) for(int i=p;i<q;i++)
ll gcd(ll a,ll b){ if(b==0) return a;    return gcd(b,a%b);}
ll lcm(ll a,ll b) { return (a/gcd(a,b)*b);}
ull power(ull a, ull b, ll m) {a %= m;  ull res = 1;  while (b > 0) { if (b & 1) res = res * a % m;  a = a * a % m;  b >>= 1; }  return res%m; }
/*bool prime[MAX];
ull sieve(){memset(prime,true,sizeof(prime));for(ull p=2;p*p<MAX;p++){if(prime[p]==true){for(ull i=2*p;i<MAX;i+=p){prime[i]=false;}}}prime[0]=0;prime[1]=0;
}*/
using namespace std;
int solve()
{
	int n,p;
	cin>>n>>p;
	string s;
	cin>>s;
	if(p==2)
	{
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if((s[i]-'0')%2==0)		ans+=i+1;
		}
		cout<<ans;
		return 0;
	}
	if(p==5)
	{
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if((s[i]-'0')%5==0)		ans+=i+1;
		}
		cout<<ans<<endl;
		return 0;
	}
	reverse(s.begin(),s.end());
	int ans[n],pref[n];
	int p2=1;
	for(int i=0;i<n;i++)
	{
		int x=(s[i]-'0')*power(10,i,p);
		ans[i]=x;
	}
	pref[0]=ans[0]%p;
	for(int i=1;i<n;i++)
		pref[i]=(pref[i-1]+ans[i])%p;
	int sum=0;
	mii mp;
	for(int i=0;i<n;i++)
	{
		if(pref[i]==0)
			sum++;
		sum+=mp[pref[i]];
		mp[pref[i]]++;
	}
	cout<<sum<<endl;

}
signed main()
{
	fastio;
//	test
		solve();
}
