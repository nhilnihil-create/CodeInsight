#include <bits/stdc++.h>
 
using namespace std;

using ll = long long;
 
int main(){
	ll n; cin >> n;
	string s; cin >> s;
	ll r = 0, g = 0, b = 0, ans = 0;
	for(ll i = 0; i < n; ++i){
		if(s[i] == 'R')r++;
		else if(s[i] == 'G')g++;
		else b++;
	}
	ans = r * g * b;
	for(ll i = 0; i < n; ++i){
		for(ll j = 1; j  <= n; ++j){
			ll kanta = i;
			ll kanta1 = i + j;
			ll kanta2 = kanta1 + j;
			if(kanta2 < n){
				if(s[kanta] != s[kanta2] && s[kanta] != s[kanta1] && s[kanta1] != s[kanta2]){
					ans--;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
