#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long int a,b,c,d;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	long long int ans=a*c;
	ans=max(a*d,ans);
	ans=max(b*c,ans);
	ans=max(b*d,ans);
	printf("%lld\n",ans);
}