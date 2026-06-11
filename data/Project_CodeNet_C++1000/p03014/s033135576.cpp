#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll H, W;
ll dpl[2005][2005];
ll dpr[2005][2005];
ll dpu[2005][2005];
ll dpd[2005][2005];

int main(){
	cin >> H >> W;
	vector<string> S(H);
	rep(i, H) cin >> S[i];


	rep(i, H) {
		ll cur = 0;
		rep(j, W) {
			dpl[i][j] = cur;
			if(S[i][j] == '#') {
				cur = 0;
			} else {
				cur++;
			}
		}
	}

	rep(i, H) {
		ll cur = 0;
		for(ll j = W - 1; j >= 0; j--) {
			dpr[i][j] = cur;
			if(S[i][j] == '#') {
				cur = 0;
			} else {
				cur++;
			}
		}
	}


	rep(j, W) {
			ll cur = 0;
		rep(i, H) {
			dpu[i][j] = cur;
			if(S[i][j] == '#') {
				cur = 0;
			} else {
				cur++;
			}
		}
	}

	rep(j, W) {
			ll cur = 0;
		for(ll i = H - 1; i>= 0; i--){
			dpd[i][j] = cur;
			if(S[i][j] == '#') {
				cur = 0;
			} else {
				cur++;
			}
		}
	}

	ll ans = 0;
	rep(i, H) {
		rep(j, W) {
			if(S[i][j] == '#') continue;

			ans = max(ans, dpl[i][j] + dpr[i][j] + dpu[i][j] + dpd[i][j] + 1);

		}
	}
	cout << ans << endl;

}
