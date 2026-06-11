#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],sum[200005];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i],sum[i]=sum[i-1]+a[i];
	int ans=1e18;
	for(int i=1;i<=n;++i){
		int l=sum[i],r=sum[n]-sum[i];
		ans=min(ans,abs(r-l));
	}
	cout<<ans;
	return 0;	
}