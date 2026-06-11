#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 2019; // faster i f const

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

int main(){
	string s; cin >> s;
	reverse(s.begin(), s.end());
	//cout << s << '\n';
	int n = s.size();
	ll ans=0, ps=0;
	map<ll,ll> mds;
	mds[0]=1;
	for(int i=0; i<n; i++){
		(ps += modpow(10, i) * (s[i]-'0'))%=mod;
		//cout << ps << ' ';
		mds[ps]++;
	}
	for(auto a : mds){
		//cout << a.first << ' ' << a.second << '\n';
		
		int k = a.second;
		ans+=(k*(k-1))/2;
	}
	cout << ans;
}