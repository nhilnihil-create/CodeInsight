#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
#define mod 1e9+7
#define debug(x) cout<<x<<endl;
#define fi first
#define se second
int main(){
	ll n; cin>>n;
	vector<pair<int,int>> v(n);
	for(int i=0;i<n;i++) cin>>v[i].se>>v[i].fi;
	sort(v.begin(),v.end());
	ll cd=0;
	bool ans=1;
	for(ll i=0;i<n;i++){
		ll ft=cd+v[i].se;
		if(ft>v[i].fi){
			ans=0;
			break;
		}else{
			cd=cd+v[i].se;
		}
	}
	if(ans) cout<<"Yes";
	else cout<<"No";
}
