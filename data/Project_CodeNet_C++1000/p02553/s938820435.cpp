#include<bits/stdc++.h>
using namespace std;
long long int t[11]={0};
int main()
{
	long long int max,a,b,c,d;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);	
	max=a*d;
	t[2]=a*c;
	t[3]=b*c;
	t[4]=b*d;
	for (int i=2;i<=4;i++)
	 if (max<t[i]) max=t[i];
	printf("%lld\n",max);
	return 0;
}