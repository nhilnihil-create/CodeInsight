#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)

signed main(){
	ll n; cin>>n;
	vl vec(n);
	map<ll,ll> mp;
	set<ll> s;
	rep(i,0,n){
		cin>>vec[i];
		mp[vec[i]]++;
		s.insert(vec[i]);
	}
	ll ans=0;
	rep(i,0,n){
		bool ok=true;
		if(mp[vec[i]]>1){
			continue;
		}
		for(ll j=(s.count(1) ? 1:2);j*j<=vec[i];j++){
			if(vec[i]==j) continue;
			if(vec[i]%j==0 && s.count(j)){
				ok=false;
				break;
			}
			else if(vec[i]%j==0 && s.count(vec[i]/j)){
				ok=false;
				break;
			}
		}
		if(ok){
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
}
