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
		ll a,b;
		cin>>a>>b;
		ch.push_back(make_pair(b,a));
	}
	sort(ch.begin(),ch.end());
	ll ans=0;
	for(ll i=0;i<n;i++){
		ans+=ch[i].second;
		if(ans>ch[i].first){
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	// your code goes here
	return 0;
}