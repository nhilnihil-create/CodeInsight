#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<set>
#include<stack>
#include<queue>
using namespace std;
int main()
{
 int n,m,k;
 long long int a[200002],b[200002];//
 int possa=0;
 long long int ssx=0,ax;//
 scanf("%d %d %d",&n,&m,&k);
 for(int i=1;i<=n;i++)
 {
	scanf("%lld",&a[i]);
	ssx+=a[i];
	if(ssx<=k){possa=i; ax=ssx;}//possaはAだけ読んだ時に読める本の数 その時にかかる時間がax
 }
 for(int i=1;i<=m;i++)
 {
	scanf("%lld",&b[i]);
 }
 int nj=1;
 long long int bx=0;//
 int ans=possa;
 for(int i=possa;i>=0;i--)
 {
	for(int j=nj;j<=m;j++)
	{
	 if(ax+bx+b[nj]<=k){bx+=b[nj]; nj++; ans=max(ans,(i+j));}
	 else{break;}
	}
 ax-=a[i]; //axはiを読むまでにかかる時間を表す
 }
 printf("%d",ans);
}