#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
#include<map>
#include<set>
#define maxn 1000005
#define lson (now<<1)
#define rson ((now<<1)|1)
#define mid ((nl+nr)>>1)
using namespace std;
typedef long long ll;
int n;
int a[maxn];
int cnt[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),cnt[a[i]]++;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt[a[i]]>1) continue;
		int flag=1;
		if(a[i]==1)
		{
			ans++;
			continue;
		}
		for(int j=1;j*j<=a[i];j++)
		{
			if(a[i]%j==0)
			{
				if(cnt[j])
				{
					flag=0;
					break;
				}
				if(j!=1 && cnt[a[i]/j])
				{
					flag=0;
					break;
				}
			}
		}
		ans+=flag;
	}
	printf("%d\n",ans);
}