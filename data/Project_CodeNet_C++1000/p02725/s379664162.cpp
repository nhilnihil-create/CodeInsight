#include<bits/stdc++.h>
using namespace std;

int n,k,ans;
int a[200010];

int main()
{
	scanf("%d%d",&k,&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=a[2]-a[1];
	for(int i=2;i<n;i++) ans=max(ans,a[i+1]-a[i]);
	ans=max(ans,a[1]+k-a[n]);
	printf("%d\n",k-ans);
	return 0;
}