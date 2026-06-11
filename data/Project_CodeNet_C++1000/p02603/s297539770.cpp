#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[110];
int main(){
	ll n;
	cin>>n;
	ll ans=1000;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n-1;i++){
		if(a[i]<a[i+1])ans+=ans/a[i]*(a[i+1]-a[i]);
	}
	cout<<ans;
	return 0;
}
