#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mx=1e9;
int s;
bool check(int a,int b,int c,int d)
{
	int tmp1=0,tmp2=0;
	if(min(a,c)<0)
	{
		tmp1=-min(a,c);
	}
	if(min(b,d)<0)
	{
		tmp2=-min(b,d);
	}
	if(a+tmp1<=mx&&c+tmp1<=mx&&b+tmp2<=mx&&d+tmp2<=mx)
	{
		printf("%lld %lld %lld %lld %lld %lld",tmp1,tmp2,a+tmp1,b+tmp2,c+tmp1,d+tmp2);
		return 1;
	}
	return 0;
}
main()
{
	scanf("%lld",&s);
	int t=max(1ll,(int)sqrt(s)-1);
	for(;t<=1e9;t++)
	{
		int tmp=t*t-s;
		if(tmp<0)continue;
		if(tmp==0)
		{
			check(0,t,t,0);
			return 0;
		}
		for(int i=sqrt(tmp);i>=1;i--)
		{
			if(tmp%i==0)
			{
				if(check(t,i,tmp/i,t))return 0;
			}
		}
	}
}
/*
999469992399999999
1000000000000000000
*/