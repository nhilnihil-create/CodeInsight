#include<iostream>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
int main()
{
	ll a[3],b[3],s[10];
	for(int i=0;i<2;i++) cin>>a[i];
	for(int i=0;i<2;i++) cin>>b[i];
	int t=0;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			ll sum=a[i]*b[j];
			s[t++]=sum;
		}
	}
	sort(s,s+t);
	printf("%lld\n",s[t-1]);
} 