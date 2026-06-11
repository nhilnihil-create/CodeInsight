#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

ll ser(ll n){
	return (n*(n+1))/2;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	ll n;
	cin>>n;
	vector<ll>cnt;
	for(ll i=2;i*i<=n;i++){
		ll t=0;
		while(n%i==0){
			n=n/i;
			t++;
		}
		if(t) cnt.push_back(t);
	}

	if(n>1) cnt.push_back(1);

	sort(cnt.begin(),cnt.end());

	ll ans=0;

	for(ll now:cnt){
		ll lo=1,hi=1e5;
		while(hi-lo>1){
			ll mid=(lo+hi)/2;
			if(ser(mid)<=now){
				lo=mid;
			}else{
				hi=mid;
			}
		}
		if(ser(hi)<=now){
			//cout<<hi<<endl;
			ans+=hi;
		}
		else{
			//cout<<lo<<endl;
			ans+=lo;
		}
	}

	cout<<ans<<endl;
	return 0;
}