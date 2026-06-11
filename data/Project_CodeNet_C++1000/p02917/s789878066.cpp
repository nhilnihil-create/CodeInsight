#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int N;
	cin >> N;
	int B[N];
	for(int i = 0; i < N; i++) cin >> B[i];

	int ans = B[0] + B[N - 2];
	for(int i = 1; i < N - 1; i++) {
		ans += min(B[i - 1], B[i]);
	}
	cout << ans;
	return 0;
}
