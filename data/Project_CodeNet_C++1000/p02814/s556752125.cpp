#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long int ll;
ll gcd(ll a,ll b)
{
	return b==0?a:gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
	return a*b/gcd(a,b);
}
ll n,m,arr[100006];
int main()
{
	ios;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>arr[i];
	}
	ll now=1;
	for(int i=1;i<=n;++i)
	{
		now=lcm(now,arr[i]/2);
		if(now>m)break;
	}
	if(now>m){cout<<0<<'\n';return 0;}
	int flag=1;
	for(int i=1;i<=n;++i)
	{
		int temp=now*2/arr[i];
		if(temp%2==0){flag=0;break;}
	}
	if(flag==0){cout<<0<<'\n';return 0;}
	else
	{
		int num=m/now;
		if(num&1){cout<<num/2+1<<'\n';}
		else cout<<num/2<<'\n';
	}
}