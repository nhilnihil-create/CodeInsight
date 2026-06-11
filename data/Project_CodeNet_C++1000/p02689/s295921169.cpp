#include<bits/stdc++.h>
const int M=1e9+7;// M=1e9+7;//M=300000;//
const int N=2e6+5;
typedef long long int ll;
using namespace std;
 
ll cnt(0),sum(0),n,m,x,y,t,i,j,temp,k,ans(0),mn(M),mx(-9e9);
vector<ll> v[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	ll a[n+1];
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i=1;i<=n;i++)
	{
		bool flag=false;
		//sort(v[i].begin(),v[i].end());
		for(j=v[i].size()-1;j>=0;j--)
		{
			if(a[v[i][j]]<a[i])
			{
				continue;
			}else{
				break;
			}
		}
		if(j<0)
		{
			ans++;
		}
	}
	cout<<ans;
	
}