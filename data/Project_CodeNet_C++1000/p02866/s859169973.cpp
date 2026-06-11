#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	int n;cin>>n;
	int d[n];
	map<int,ll> mp;//長さごとに数える
	rep(i,n){
		cin>>d[i];
		mp[d[i]]++;
	}

	if(d[0]!=0||mp[0]>1||(mp[0]>0&&d[0]!=0)){
		cout<<0<<"\n";
		return 0;
	}
	ll ans=1,mod=998244353;
	for(int i=1;i<n;i++){
		ans=(ans*mp[d[i]-1])%mod;//iに隣接して1に最も近いものの種類をかけていけば解になる
	}
	cout<<ans<<"\n";

}