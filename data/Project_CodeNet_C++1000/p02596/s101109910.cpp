#include<bits/stdc++.h>
#define ll long long 
#define MM(arr,x) memset(arr,x,sizeof(arr))
#define INF 0x3f3f3f3f
#define Maxn 1e5+10;
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	ll ans=0,k,now=0;
	cin>>k;
	while(ans<=99999999)
	{
		ans++;
		now=(now*10+7)%k;
		if(now==0) 
		{
			cout<<ans;
			return 0;
		}
	}
	cout<<-1;
	return 0;
} 