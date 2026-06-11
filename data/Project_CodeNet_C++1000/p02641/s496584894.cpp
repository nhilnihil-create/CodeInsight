#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
#include<map>
#include<set>
#define maxn 200005
#define lson (now<<1)
#define rson ((now<<1)|1)
#define mid ((nl+nr)>>1)
using namespace std;
typedef long long ll;
int a[maxn];
int cnt[maxn];
int main()
{
	int x,n;
	cin>>x>>n;
	for(int i=1;i<=n;i++)
	{
		int y;
		cin>>y;
		cnt[y]++;
	}
	for(int i=0;i<=100;i++)
	{
		if(!cnt[x-i])
		{
			printf("%d\n",x-i);
			return 0;
		}
		if(!cnt[x+i])
		{
			printf("%d\n",x+i);
			return 0;
		}
	}
}