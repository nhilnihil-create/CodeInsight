#include<iostream>
#include<string>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<utility>
#include<iterator>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
//#define t ll t;cin>>t;while(t--)
#define nn cout<<endl;
#define ff(a,n) for(ll i=a;i<n;i++)
#define cY cout<<"YES\n"
#define cN cout<<"NO\n"
#define cy cout<<"Yes\n"
#define cn cout<<"No\n"
#define sc second
#define fs first
#define c(a) cout<<a<<endl

void solve()
{
	ll n; cin>>n; ll a[n];
	ff(0,n)cin>>a[i];
	ll ans=0;
	for(ll i=0;i<n;i++)
	{
		for(ll j=i+1;j<n;j++)
		{
			if(a[i]==a[j])continue;
			for(ll k=j+1;k<n;k++)
			{
				if(a[i]==a[k]||a[j]==a[k])continue;
				if(a[i]+a[j]>a[k]&&a[i]+a[k]>a[j]&&a[j]+a[k]>a[i])ans++;
			} 
		} 
	} 
	cout<<ans<<endl;
}

int main()
{
	solve();
}
/*
10
9 4 6 1 9 6 10 6 6 8



*/
