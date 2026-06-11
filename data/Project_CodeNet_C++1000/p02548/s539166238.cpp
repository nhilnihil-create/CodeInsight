#include<bits/stdc++.h>
using namespace std;
#define mem(a) memset(a,0,sizeof(a))
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define ll long long
//不要再爆long long了！！！！！！！！不要再爆long long了！！！！！！！ 

int main()
{
	ll n,s=0;
	cin>>n;
	n--;
	for(ll i=1;i<=n;i++)
	{
		s+=n/i;
	}
	printf("%lld\n",s);
	return 0;
}