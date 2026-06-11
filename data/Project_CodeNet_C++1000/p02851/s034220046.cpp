#include<cstdio>
#include<cstdlib>
#include<map>
using namespace std;
int m,n,i,j;
#define maxn 200010
long long a[maxn],sum[maxn],k,ans;
map<long long,long long>mp;
int main()
{
	scanf("%d%lld",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(i=n;i>=1;i--)
	{
		mp[(sum[i]-i)%k]++;
		if(n-i+1>=k)
		{
			int p=i+k-1;
			mp[(sum[p]-p)%k]--;
		}
		ans+=mp[(sum[i-1]-i+1)%k];
	}

	printf("%lld\n",ans);
	return 0;
}