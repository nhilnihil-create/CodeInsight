#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

signed main() {
	ll n, d;
	cin >> n >>d;
	vector<vector<ll>> x(n, vector<ll>(d));
	rep(i, n){
		rep(j, d){
			cin >> x.at(i).at(j);
		}
	}
	ll ans = 0;
	for(ll i = 0; i < n; i++){
		for(ll j = i + 1; j < n; j++){
			ll kazu = 0;
			for(ll k = 0; k < d; k++){
				ll siki = abs(x[i][k] - x[j][k]);
				kazu += siki * siki;
			}
			bool tadashi = false;
			for(ll k = 0; k <= kazu; k++){
				if(k * k == kazu) tadashi = true;
			}
		if(tadashi) ans++;
		}
	}
	cout << ans << endl;
}
