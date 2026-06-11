#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,tot;
queue<ll>q;
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=9;i++)q.push(i);
	while(!q.empty())
	{
		ll tx=q.front(); q.pop();
		if(++tot==n)
		{
			printf("%lld\n",tx);
			exit(0);
		}
		if(tx%10>0)q.push(tx*10+tx%10-1);
		q.push(tx*10+tx%10);
		if(tx%10<9)q.push(tx*10+tx%10+1);
	}
	return 0;
}