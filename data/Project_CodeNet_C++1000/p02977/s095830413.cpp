/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-01-22 16:47:46
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
#include<vector>
int n,l;
void print(std::vector<int> v){ fr(i,1,v.size()-1) printf("%d %d\n",v[i-1],v[i]); }
int main()
{
	n=read(); l=1;
	if((n&(-n))==n){ printf("No\n"); return 0; }
	printf("Yes\n");
	while((l<<1)<=n) l<<=1;
	print({n,l,n-l,n+n,l+n,n-l+n});
	fr(i,1,n-l-1) print({i,i+l,l,i+n,i+l+n});
	for(int i=l-1;i-1>n-l;i-=2) print({i,i-1,1,i+n,i-1+n});
	if(!(n&1)) printf("%d %d\n%d %d\n",n-l+1,n-l,l+1,n-l+1+n);
	return 0;
}