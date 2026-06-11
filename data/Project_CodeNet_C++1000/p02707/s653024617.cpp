#include<cstdio>
#include<algorithm>
#include<functional>
#include<cstring>
#include<queue>
using namespace std;
 
int main(void)
{
	int n,i,a,cnt[200001];
	scanf("%d",&n);
	for(i=1;i<=n;i++)	cnt[i]=0;
	for(i=2;i<=n;i++)	{
		scanf("%d",&a);
		cnt[a]++;
	}
	for(i=1;i<=n;i++)	printf("%d\n",cnt[i]);
	return 0;
}