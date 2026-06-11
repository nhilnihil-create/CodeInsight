#include<cstdio>
#include<algorithm>
using namespace std;
int n,cnt,mp[300005],ans[300005],del[300005],siz[300005];
int main()
{
	scanf("%d",&n);
	for(int i=1,a;i<=n;i++)
	{
		scanf("%d",&a);
		if(!mp[a])mp[a]=++cnt;
		siz[mp[a]]++;
	}
	for(int i=1;i<=cnt;i++)del[1]++,del[siz[i]+1]--;
	for(int i=1,nw=0;i<=n;i++)nw+=del[i],ans[i]=ans[i-1]+nw;
	for(int k=1,te=n;k<=n;k++)
	{
		while(ans[te]<te*k)te--;
		printf("%d\n",te);
	}
}