#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int N, K;
	cin >> N >> K;
	int h[N];
	for(int i = 0; i < N; i++) cin >> h[i];
	ll ans = 0;
	for(int i = 0; i < N; i++) {
		if(K <= h[i]) ans++;
	}
	cout << ans << "\n";
}