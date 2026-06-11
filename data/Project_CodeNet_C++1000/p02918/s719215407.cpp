#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int N, K;
	cin >> N >> K;
	string S;
	cin >> S;
	int ans = 0;
	for(int i = 1; i < N; i++)
		if(S[i - 1] == S[i]) ans++;
	if(N - ans == 2) {
		if(K == 0)
			cout << ans << "\n";
		else
			cout << N - 1 << "\n";
		return 0;
	}
	cout << ans + min(2 * K, N - ans - 1) << "\n";
	return 0;
}
