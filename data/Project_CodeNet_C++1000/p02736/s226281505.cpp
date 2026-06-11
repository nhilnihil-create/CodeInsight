#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<time.h>
using namespace std;
#define ll long long
#define re register
#define mp make_pair
typedef pair<int,int> pii;
inline int gi()
{
	int sum=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return f*sum;
}
const int N=1000010;
int n,a[N];
int main()
{
	n=gi();for(int i=1;i<=n;i++)scanf("%1d",&a[i]),a[i]--;
	int fl=0;
	for(int i=1;i<=n;i++)if(a[i]==1)fl=1;
	if(fl)for(int i=1;i<=n;i++)a[i]%=2;
	int ans=0;
	for(int i=1;i<=n;i++)
		if(((n-1)&(i-1))==i-1)ans^=a[i];
	printf("%d\n",ans);
	return 0;
}