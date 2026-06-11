#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define MAX 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;

ll ans;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N,K,S;
	cin >> N >> K >> S;
	
	ll cnt = 0;

	rep(i, K) {
		if (cnt != N - 1) {
			cout << S << " ";
			cnt++;
		}
		else {
			cout << S << endl;
		}
	}

	ll nots;
	if (S == 1e9) {
		nots = 1;
	}
	else {
		nots = S + 1;
	}
	rep(i, N - K) {
		if (cnt != N - 1) {
			cout << nots << " ";
			cnt++;
		}
		else {
			cout << nots << endl;
		}
		
	}

	return 0;
}