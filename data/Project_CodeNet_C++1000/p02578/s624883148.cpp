#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(void){
	int n,now,ans=0;
	scanf("%lld",&n);
	int a[n];
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	now=a[0];
	for(int i=1;i<n;i++){
		if(a[i]>=now) now=a[i];
		else ans+=now-a[i];
	}
	cout<<ans<<endl;
	return 0;
}