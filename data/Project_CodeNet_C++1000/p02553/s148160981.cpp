#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define F first
#define S second
#define pb push_back
#define f(i,s,n) for(int i=(int)s;i<=(int)n;++i)
#define Fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
void solve()
{
	ll a,b,c,d;cin>>a>>b>>c>>d;
	ll ans=max(a*c,max(a*d,max(b*c,b*d)));
	cout<<ans<<'\n';
}
int main()
{	Fast;
//	int t;cin>>t;
//	while(t--)
	solve();
}