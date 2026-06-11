#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long f[200005];
int main()
{
	int i,n,m;
	long long sum = 0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%lld",&f[i]);
	if(m<n)
	{
		sort(f,f+n);
		for(i=0;i<n-m;i++)
			sum += f[i];
	}
	printf("%lld",sum);
	return 0;
}