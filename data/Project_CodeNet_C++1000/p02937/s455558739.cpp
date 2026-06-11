#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	string t,s;
	cin>>t>>s;
	vector<ll>ch[26];
	for(ll i=0;i<t.size();i++){
		ll now=t[i]-'a';
		ch[now].push_back(i+1);
	}
	ll cnt=1,ans=0;
	for(ll i=0;i<s.size();i++){
		ll now=s[i]-'a';
		auto itr=lower_bound(ch[now].begin(),ch[now].end(),cnt);
		if(itr==ch[now].end()){
			ans+=t.size()-cnt+1;
			cnt=1;
		}
		itr=lower_bound(ch[now].begin(),ch[now].end(),cnt);
		if(itr==ch[now].end()){
			cout << -1;
			return 0;
		}
		ans+=*itr-(cnt-1);
		cnt=*itr+1;
	}
	cout <<ans;
	return 0;
}