#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int n,a[1000005],ans;
char s[1000005];
int C(int n,int m){return (n&m)==m;}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	if(n==1) printf("%c",s[1]);
	else
	{
		n--;
		for(int i=1;i<=n;i++) a[i]=abs(s[i]-s[i+1]);
		int flag1=0;
		for(int i=1;i<=n;i++) if(a[i]==1) flag1=1;
		if(!flag1) for(int i=1;i<=n;i++) a[i]/=2;
		flag1^=1;
		for(int i=1;i<=n;i++) ans^=C(n-1,i-1)*(a[i]&1);
		printf("%d\n",ans<<flag1);
	}
}