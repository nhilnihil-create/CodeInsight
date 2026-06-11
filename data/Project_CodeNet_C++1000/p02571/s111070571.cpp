#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll count(string s, string g){
	ll cnt = 0;
	for(ll i=0;i<g.length();++i){
		if(s[i] != g[i]) ++cnt;
	}

	return cnt;
}


ll findans(string s, string p){
	ll ans;

	string g = s.substr(0,p.length());
	ans = count(g,p);

	for(ll i=g.length();i<s.length();++i){
		g.erase(g.begin());
		g += s[i];
		ans = min(ans, count(g,p));
	}
	return ans;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t=1;
	// cin>>t;

	while(t--){
		string s,p;
		cin>>s>>p;

		cout<<findans(s,p)<<"\n";

	}	

	return 0;
}