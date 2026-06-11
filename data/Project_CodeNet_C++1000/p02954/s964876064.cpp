#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main(){
	string s;
	cin >> s;
	ll n=s.size();
	vector<ll> lr;
	vector<ll> rl;
	lr.push_back(-1);
	for(ll i=0;i<n-1;i++){
		if(s[i]=='R'&&s[i+1]=='L') rl.push_back(i);
		if(s[i]=='L'&&s[i+1]=='R') lr.push_back(i);
	}
	lr.push_back(n-1);
	vector<ll> res(n,0);
	for(ll i=0;i<rl.size();i++){
		ll countR=rl[i]-lr[i];
		ll countL=lr[i+1]-rl[i];
		res[rl[i]]=countR-(countR/2)+countL/2;
		res[rl[i]+1]=countL-(countL/2)+countR/2;
	}
	for(ll i=0;i<n;i++) cout << res[i] << endl;
}
