#include<iostream>
#include<cmath>
using namespace std;

long long n,m,a,b,ans;

int main()
{
	scanf("%lld",&n);
	m=sqrt(n);
	for(int i=m;i>=1;i--)
		if(n%i==0)
		{
			a=i;
			b=n/i;
			break;
		}
	ans=a+b-2;
	printf("%lld",ans);
	
	return 0;
} 