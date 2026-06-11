#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n;
	cin>>n;
	ll x=sqrt(n);
	ll ans=0;
	for(int i=2;i<=x;i++){
		ll cnt=0;
		while(n%i==0){
			n/=i;
			cnt++;
		}
		ll j=0;
		while(1){
			if(j*(j+1)/2<=cnt&&cnt<(j+1)*(j+2)/2)break;
			j++;
		}
		ans+=j;
	}
	if(n!=1)ans++;
	cout<<ans;
	return 0;
}
