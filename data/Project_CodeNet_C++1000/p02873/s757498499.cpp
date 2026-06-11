
// A - ><

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int l_min[500001];
int r_min[500001];

int main() {
	string S;
	cin >> S;

	int N = S.size();

	// from left
	l_min[0] = 0;
	for (int i=0; i<N; i++) {
		if (S[i] == '<') {
			l_min[i+1] = l_min[i] + 1;
		} else {
			l_min[i+1] = 0;
		}
	}

	// from right
	r_min[N] = 0;
	for (int i=N-1; i>=0; i--) {
		if (S[i] == '>') {
			r_min[i] = r_min[i+1] + 1;
		} else {
			r_min[i] = 0;
		}
	}

	ll ans = 0;

	for (int i=0; i<=N; i++) {
		//cout << l_min[i] << " " << r_min[i] << endl;
		ans += max(l_min[i], r_min[i]);
	}

	cout << ans << endl;

	return 0;
}