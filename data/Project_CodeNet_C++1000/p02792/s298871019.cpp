#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
map<pair<int,int>,int>mp;
pair<int,int> dg(int n){
	pair<int,int> ret;
	ret.first=n%10;
	while(n){
		int dd=n%10;
		n/=10;
		if(n==0)ret.second=dd;
	}
	return ret;
}
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		mp[dg(i)]++;
	}
	ll ans=0;
	for(auto u:mp){
		pair<int,int> pp={u.first.second,u.first.first};
		ans+=mp[pp]*u.second;
	}
	cout<<ans;
	return 0;
}