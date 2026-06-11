#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

const int M=3e5+5;
int cnt[M],ccnt[M];

// f(x) the max length of the group if divided into x groups
// f(x) = sum(min(cnt[i],x)) / x
// f(x) = (sum_{1~x}(i*ccnt[i]) + x*sum_{x+1~n}(ccnt[i]))/x
int f[M];

int main()
{
	int n,a;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		cnt[a]++;
	}
	for(int i=1;i<=n;i++)
		ccnt[cnt[i]]++;
	int sumcnt=0;
	for(int i=1;i<=n;i++)
		sumcnt+=ccnt[i];
	//cout<<sumcnt<<endl;
	int ncnt=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=i*ccnt[i];
		ncnt+=ccnt[i];
		f[i]=(sum+i*(sumcnt-ncnt))/i;
		//cout<<i<<" "<<sum<<" "<<ncnt<<" "<<f[i]<<endl;
	}
	int j=n;
	for(int i=1;i<=n;i++)
	{
		while(j&&f[j]<i) j--;
		printf("%d\n",j);
	}
	return 0;
}