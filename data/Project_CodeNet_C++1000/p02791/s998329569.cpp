#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	cin>>n;
	ll p[n+1],mini[n+1];
	for(ll i=1;i<=n;i++)
	cin>>p[i];
	mini[1]=p[1];
	for(ll i=2;i<=n;i++)
	mini[i]=min(mini[i-1],p[i]);
	ll cnt=0;
	for(ll i=1;i<=n;i++)
	if(mini[i]==p[i])
	cnt++;
	cout<<cnt;
	
}