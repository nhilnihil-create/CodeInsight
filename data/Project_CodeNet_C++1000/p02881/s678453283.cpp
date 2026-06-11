#include<cstdio>
#include<algorithm>
#include<iostream>
typedef long long LL;
using namespace std;
LL a,b,x,ans;
int main()
{
	cin>>x;ans=x+1;
	for(LL i=2;i*i<=x;i++)
	{
		if(x%i==0)
		ans=min(i+x/i,ans);
	}
	cout<<ans-2;
}
