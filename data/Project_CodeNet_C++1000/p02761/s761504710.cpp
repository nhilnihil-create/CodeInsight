#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int N, M;
	cin >> N >> M;
	int s[M], c[M];
	for(int i = 0; i < M; i++) cin >> s[i] >> c[i];

	int ans[N];
	for(int i = 0; i < N; i++) ans[i] = -1;
	for(int i = 0; i < M; i++) {
		s[i]--;
		if(ans[s[i]] == -1) {
			ans[s[i]] = c[i];
		} else {
			if(ans[s[i]] != c[i]) {
				cout << -1;
				return 0;
			}
			ans[s[i]] = c[i];
		}
	}
	if(ans[0] == 0 && N != 1)
		cout << -1;
	else if(ans[0] == -1 && N == 1)
		cout << 0;
	else
		for(int i = 0; i < N; i++) {
			if(ans[i] == -1) {
				if(i == 0)
					cout << 1;
				else
					cout << 0;
			} else
				cout << ans[i];
		}
	return 0;
}
