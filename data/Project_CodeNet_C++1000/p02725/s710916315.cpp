#include<bits/stdc++.h>
using namespace std;
int n,k;
int ans,a[200005];
int main(){
//	freopen("x.txt","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i)	scanf("%d",&a[i]);
	for(int i=2;i<=k;++i) ans=max(ans,a[i]-a[i-1]);
	ans=max(ans,a[1]+n-a[k]);
	cout<<n-ans<<endl;
} 