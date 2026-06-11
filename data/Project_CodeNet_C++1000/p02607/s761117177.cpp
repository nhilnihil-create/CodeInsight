#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[214514];
int main(){
	ll n;
	cin>>n;
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll a;
		cin>>a;
		if(i%2&&a%2)ans++;
	}
	cout<<ans;
	return 0;
}
