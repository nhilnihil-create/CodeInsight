#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <bitset>
using namespace std;

typedef long long LL;
const int M=1e5+5;
const int MB=60;

LL a[M];

int main()
{
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	// if xor (bit i) == 1 final 1
	// else == 0 gready to choose 1,1 pair
	LL all=0;
	for(int i=0;i<n;i++)
	    all^=a[i];
	for(int i=0;i<n;i++)
		a[i]=a[i]&(~all);
	// linear base
	int mr=0,j;
	for(int i=MB-1;i>=0;i--)
	{
		for(j=mr;j<n;j++)
			if(a[j]&(1LL<<i)) break;
		if(j==n) continue;
		swap(a[j],a[mr]);
		for(j=0;j<n;j++)
		{
			if(j!=mr&&a[j]&(1LL<<i))
				a[j]^=a[mr];
		}
		mr++;
	}
	//cout<<all<<endl;
	LL ans2=0;
	for(int i=0;i<mr;i++)
	{
		//bitset<64> bs(a[i]);
		//cout<<bs<<endl;
		ans2^=a[i];
	}
	printf("%lld\n",all+(ans2<<1));
	return 0;
}