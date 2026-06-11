#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;



int main(void) {
	int N, K; cin >> N >> K;
	vector<ll> H(N); rep(i, N)cin >> H[i];

	sort(H.begin(), H.end(), greater<ll>());

	ll ans = 0;
	for (int i = K; i < N; i++)ans += H[i];

	cout << ans << endl;

	return 0;
}