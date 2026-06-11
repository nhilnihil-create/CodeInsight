#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
int main() {
	ll n;
	cin>>n;
	map<string,ll>s;
	for(ll i=0;i<n;i++){
		string t;
		cin>>t;
		sort(t.begin(),t.end());
		s[t]++;
	}
	ll ans=0;
	for(auto itr=s.begin();itr!=s.end();itr++){
		ll val=itr->second;
		ans+=val*(val-1)/2;
	}
	cout <<ans;
	// your code goes here
	return 0;
}