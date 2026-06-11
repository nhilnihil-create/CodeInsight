#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	ll N;
	cin >> N;
	vector<ll> W(N);
	rep(i, N) cin >> W[i];

	ll ans = 100000;
	rep(i, N) {
		ll a = 0;
		ll b= 0;
		for(ll j = 0; j <= i; j++) {
			a += W[j];
		}
		for(ll j = i + 1; j < N; j++) {
			b += W[j];
		}
		ans = min(ans, abs(a - b));
	}
	cout << ans << endl;

}