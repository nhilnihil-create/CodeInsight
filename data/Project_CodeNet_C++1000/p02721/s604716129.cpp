#include<bits/stdc++.h>
using namespace std;
#define N 200010
int n,k,c,f[N],g[N],lst;
char s[N];
int main()
{
	scanf("%d%d%d",&n,&k,&c);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	  {
	  f[i]=f[i-1];
	  if(i>lst && s[i]=='o')f[i]++,lst=i+c;
	  }
	lst=n+1;
	for(int i=n;i>=1;i--)
	  {
	  g[i]=g[i+1];
	  if(i<lst && s[i]=='o')g[i]++,lst=i-c;
	  }
	for(int i=1;i<=n;i++)
	  if(f[i]>f[i-1] && g[i]>g[i+1] && f[i]+g[i]==k+1)
	    printf("%d\n",i);
	return 0;
}