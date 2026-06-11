#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll x,n;
	cin>>x>>n;
	bool f[110]={};
	for(int i=0;i<n;i++){
		ll a;
		cin>>a;
		f[a]=1;
	}
	ll num=1e9,ans;
	for(int i=101;i>=0;i--){
		if(f[i])continue;
		if(abs(x-i)<=num){
			num=abs(x-i);
			ans=i;
		}
		//cout<<num<<' '<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
