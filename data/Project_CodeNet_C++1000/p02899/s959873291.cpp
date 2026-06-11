#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	   scanf("%d",&a[i]),ans[a[i]]=i;
	for(int i=1;i<=n;++i)
	   printf("%d ",ans[i]);
	printf("\n");
	return 0;
}