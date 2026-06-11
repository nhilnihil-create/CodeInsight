#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;


int main(){
	string s;
	ll k;
	cin >> s >> k;
	ll n = s.length();
	vector<ll> ren;

	if (n == 1){
		cout << k/2 << endl;
		return 0;
	}

	for (int i = 0; i < n-1; ){
		if (s[i] == s[i+1]){
			int j = 1;
			while(s[i] == s[i+j]){
				j++;
				if (i+j == n) break;
			}
			ren.push_back(j);
			i += j;
		}else{
			ren.push_back(1);
			if (i == n-2) ren.push_back(1);
			i++;
		}
	}
	
	if (s[0] == s[n-1]){
		if (ren[0] == n){
			cout << n*k/2 << endl;
		}else{
			ll ans = 0;
			ll temp = ren[0] + ren.back(); 
			ans += (ll)(temp/2)*(k-1);
			ans += ren[0]/2;
			ans += ren.back()/2;
			for (int i = 1; i < (int)ren.size()-1; i++){
				ans += (ll)(ren[i]/2)*k;
			}
			cout << ans << endl;
		}
	}else{
		ll ans = 0;
		for (int i = 0; i < (int)ren.size(); i++){
			ans += (ll)(ren[i]/2)*k;
		}
		cout << ans << endl;
	}
	
 	return 0;
 }