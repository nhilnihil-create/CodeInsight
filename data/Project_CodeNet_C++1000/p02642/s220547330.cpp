#include<bits/stdc++.h>
const int M=1e9+7;// M=1e9+7;//M=300000;//
const int N=2e6+5;
typedef long long int ll;
using namespace std;
 
ll cnt(0),sum(0),n,x,y,t,i,j,temp,k,ans(0),mn(M),mx(-9e9);
ll table[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	ll a[n];
	//memset(table,0,sizeof(table));
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		table[a[i]]++;
	}
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		for(j=2;j*a[i]<=a[n-1];j++)
		{
			table[a[i]*j]++;
		}
	}
	for(i=0;i<n;i++)
	{
		if(table[a[i]]<=1)
		{
			ans++;
		}
	}
	cout<<ans;
}