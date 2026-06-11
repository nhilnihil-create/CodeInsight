#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	string s,t;
	cin>>s>>t;
	vector<ll>a[26];
	for(ll i=0;i<s.size();i++){
		ll now=s[i]-'a';
		a[now].push_back(i+1);
	}
	for(ll i=0;i<26;i++){
		sort(a[i].begin(),a[i].end());
	}
	ll ans=0;
	ll cnt=1;
	for(ll i=0;i<t.size();i++){
		ll now=t[i]-'a';
		if(a[now].size()==0){
			cout << -1;
			return 0;
		}
		auto itr=lower_bound(a[now].begin(),a[now].end(),cnt);
		if(itr==a[now].end()){
			ans+=s.size()-cnt+1;
			itr=a[now].begin();
			ans+=*itr;
			cnt=*itr+1;
		}
		else{
			ans+=*itr-cnt+1;
			cnt=*itr+1;
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}