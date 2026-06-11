#include <bits/stdc++.h>
#include <unordered_set>
#include <random>
using namespace std;
#define ll long long
#define fr first
#define sc second
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M; cin >> N >> M;
	int digit[6];
	memset(digit, -1, sizeof(digit));
	while (M--) {
		int a, b; cin >> a >> b;
		if (digit[a] != -1 && digit[a] != b) {
			cout << -1 << '\n';
			return 0;
		}
		digit[a] = b;
	}
	if (digit[1] == -1) {
		if (N != 1) digit[1] = 1;
		else digit[1] = 0;
	}
	for (int i = 2; i <= N; i++) if (digit[i] == -1) digit[i] = 0;

	if (N != 1 && digit[1] == 0) cout << -1 << '\n';
	else for (int i = 1; i <= N; i++) cout << digit[i];

	return 0;
}