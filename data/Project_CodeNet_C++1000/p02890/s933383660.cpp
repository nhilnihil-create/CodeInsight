#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int M=3e5+5;
int a[M],cnt[M];

int main()
{
	int n; scanf("%d",&n);
	int nu;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&nu);
		a[nu]++;
	}
	for(int i=1;i<=n;i++)
		cnt[a[i]]++;
	int ans=n;
	int j=n;
	for(int i=1;i<=n;i++)
	{
		while(j>ans/i)
		{
			int ncnt=0;
			int tmp=ans/i;
			while(j>tmp)
			{
				ans-=(j-tmp)*cnt[j];
				ncnt+=cnt[j];
				j--;
			}
			cnt[j]+=ncnt;
		}
		printf("%d\n",ans/i);
	}
	return 0;
}