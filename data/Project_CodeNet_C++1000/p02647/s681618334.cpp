#include<bits/stdc++.h>
using namespace std;
int n,k,a[200100],cnt[400100];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	while(k--)
	{
		bool flag=0;
		for(int i=1;i<=n;i++) if(a[i]<n) flag=1;
		if(!flag) break;
		for(int i=1;i<=n;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) cnt[max(1,i-a[i])]++,cnt[i+a[i]+1]--;
		for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
		for(int i=1;i<=n;i++) a[i]=cnt[i];
	}
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;
}