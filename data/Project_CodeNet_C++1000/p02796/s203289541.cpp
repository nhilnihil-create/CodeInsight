#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	vector<pair<ll,ll>>ch;
	for(ll i=0;i<n;i++){
		ll x,y;
		cin>>x>>y;
		ll s=x-y;
		ll e=x+y;
		ch.push_back(make_pair(e,s));
	}
	sort(ch.begin(),ch.end());
	ll r=ch[0].first;
	ll cnt=0;
	for(ll i=1;i<n;i++){
		if(r<=ch[i].second){
			r=ch[i].first;
		}
		else{
			cnt++;
		}
	}
	cout <<n-cnt;
	// your code goes here
	return 0;
}