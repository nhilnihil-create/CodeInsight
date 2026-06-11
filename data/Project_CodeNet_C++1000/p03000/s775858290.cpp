#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	ll N, X;
	cin >> N >> X;
	vector<ll> L(N);
	rep(i, N) cin >> L[i];

	ll ans = 0;
	ll cur = 0;
	for(ll i = 0; i < N; i++) {
		if(cur <= X) {
		ans++;
		}
		cur += L[i];
	}
		if(cur <= X) {
		ans++;
		}
	cout << ans << endl;
}

