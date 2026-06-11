#include<cstdio>
#include<iostream>
const long long Maxn=1000000+10;
long long a[Maxn],cnt[Maxn][2];
long long n,ans;
inline long long read()
{
	long long s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
int main()
{
	n=read();
	for(long long i=1;i<=n;++i)
	{
		a[i]=read();
		if(i-a[i]>=0)++cnt[i-a[i]][1];
		if(i+a[i]<=n)++cnt[i+a[i]][0];
	}
	for(long long i=1;i<=n;++i)
	{
		if(i-a[i]>=0)ans+=cnt[i-a[i]][0];
		if(i+a[i]<=n)ans+=cnt[i+a[i]][1];
	}
	printf("%lld\n",ans>>1);
	return 0;
}