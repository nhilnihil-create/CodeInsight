#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ll N, K;
	cin >> N >> K;
	vector<ll> A(N);
	for(auto &a : A) cin >> a;
	vector<ll> sum(N+1, 0);
	for(int i=1;i<=N;i++) {
		sum[i] = sum[i-1] + A[i-1];
	}
	map<ll,ll> mp;
	ll ans = 0;
	for(int i=0;i<=N;i++) {
		ll plus = (sum[i] - i) % K;
		if(plus < 0) plus += K;
		mp[plus]++;
		if(i >= K) {
			ll minus = (sum[i-K] - (i-K)) % K;
			mp[minus]--;
		}
		// 自分自身との組
		ans += (mp[plus] - 1);
	}
	cout << ans << endl;
}