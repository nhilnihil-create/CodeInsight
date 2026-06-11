#include<bits/stdc++.h>
using namespace std;
#define nl '\n' 
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define pii pair <int,int>
ll mod=1000000007;
int main()
{
	fast;
	int n;cin>>n;
	vector<ll> xx,yy;
	for(int i=0;i<n;i++)
	{
		ll x,y;cin>>x>>y;
		xx.push_back(x+y);
		yy.push_back(x-y);
	}
	sort(xx.begin(),xx.end());
	sort(yy.begin(),yy.end());
	ll ans=0;
	ans=max(ans,abs(xx[0]-xx[n-1]));
	ans=max(ans,abs(yy[0]-yy[n-1]));

	cout<<ans<<nl;

}