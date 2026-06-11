#include <bits/stdc++.h>
#define N 200005
using namespace std;
int k,n,a[N];
double cnt,p[1005],ans;
int main(){
	cin>>n>>k;
	for(int i=1;i<=1000;i++)p[i]=i*(i+1)*1.0/2.0/i;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=k;i++)cnt+=p[a[i]];
	ans=cnt;
	for(int i=k+1;i<=n;i++)cnt+=p[a[i]]-p[a[i-k]],ans=max(ans,cnt);
	cout<<fixed<<setprecision(8)<<ans<<endl;
	return 0;
}