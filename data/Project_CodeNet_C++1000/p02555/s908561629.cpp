#include<cstdio>
long long f[4001];
const long long mod=1e9+7;
int main()
{
	int s;
	scanf("%d",&s);
	f[0]=1;
	for(int i=0;i<s;++i)
		for(int j=3;j<=s;++j)
			f[i+j]+=f[i],f[i+j]%=mod;
	printf("%lld",f[s]);
}