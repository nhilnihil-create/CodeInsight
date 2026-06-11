#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	ll L, R;
	cin >> L >> R;

	if(R - L > 5000) {
		cout << 0 << endl;
	} else {
		ll ans = 2019;
		for(ll i = L; i <= R; i++) {
			for(ll j = i + 1; j <= R; j++) {
				ans = min(ans, (i * j)%2019);
			}
		}
		cout << ans << endl;
	}
}
