#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;
const ll INF=1e10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	ll n;
	cin>>n;
	map<ll,ll> cnt;
	for(ll i=2;i*i<=n;i++){
		while(n%i==0){
			n/=i;
			cnt[i]++;
		}
	}
	if(n!=1) cnt[n]++;
	ll ans=0;
	for(auto i:cnt){
		for(int j=1;j<=i.second;j++){
			ans++;
			i.second-=j;
		}
	}
	cout<<ans;
}
