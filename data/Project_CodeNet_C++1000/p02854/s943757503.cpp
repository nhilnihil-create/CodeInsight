#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[214514],num[214514];

int main(){
	ll n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i)num[i]=num[i-1]+a[i];
		else num[i]=a[i];
	}
	ll ans=1e18;
	for(int i=0;i<n;i++){
		ans=min(ans,abs(num[i]*2-num[n-1]));
	}
	cout<<ans;
	return 0;
}
