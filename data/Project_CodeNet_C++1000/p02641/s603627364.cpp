#include<bits/stdc++.h>
const int M=1e9+7;// M=1e9+7;//M=300000;//
const int N=2e6+5;
typedef long long int ll;
using namespace std;
 
ll cnt(0),sum(0),n,x,y,t,i,j,temp,k,ans(0),mn(M),mx(-9e9);
map<ll,ll> m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>x>>n;
	for(i=0;i<n;i++)
	{
		cin>>y;
		m[y]++;
	}
	i=x;
	while(1)
	{
		if(m[i]==0)
		{
			ans=i;
			break;
		}
		i++;
	}
	i=x;
	while(1)
	{
		if(m[i]==0)
		{
			if(abs(x-i)<=abs(ans-x))
			{
				ans=i;
			}
			break;
		}
		i--;
	}
	cout<<ans;
}