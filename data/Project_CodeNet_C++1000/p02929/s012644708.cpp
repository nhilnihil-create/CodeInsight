#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

ll MOD = 1e9 + 7;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N;
	cin >> N;

	string S;
	cin >> S;

	vector<int> T(2 * N);
	for(int i = 0; i < 2 * N; i++){
		T[i] = (S[i] == 'B' ? 1 : 0);
		if(i % 2 == 0) T[i] = 1 - T[i];
	}

	ll cnt = 0LL;
	rep(i, 2 * N) cnt += T[i];
	if(cnt != N){
		cout << 0 << endl;
		return 0;
	}

	ll ans = 1LL;
	ll t = 0LL;
	rep(i, 2 * N){
		if(T[i] == 0){
			t++;
		}else{
			ans *= t;
			ans %= MOD;
			t--;
		}
	}

	for(ll i = 1LL; i <= N; i++){
		ans *= i;
		ans %= MOD;
	}

	cout << ans << endl;

}
