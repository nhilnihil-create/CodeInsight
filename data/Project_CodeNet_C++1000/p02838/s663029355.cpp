#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define MAX 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;

ll ans,cnt;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N;
	cin >> N;

	vector<ll> A(N);
	rep(i,N){
		cin >> A[i];
	}

	ll odd = 0, even = 0;
	ll two_pow =1;

	rep(d,60){
		odd = 0;
		even = 0;
		rep(i,N){
			if(A[i] & (1LL << d)) odd++;
			else even++;
		}
		ll add = (odd * even) % MOD * two_pow % MOD;
		ans = (ans + add) % MOD;
		two_pow = (two_pow * 2) % MOD;
	}

	cout << ans << endl;

	return 0;
}