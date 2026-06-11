#include<bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int s[M];
	char c[M];
	for (int i = 0; i < M; ++i) cin >> s[i] >> c[i], s[i]--;


	int mx;
	if (N == 1) mx = 9;
	if (N == 2) mx = 99;
	if (N == 3) mx = 999;


	for (int i = 0; i <= mx; i++) {
		string i_s = to_string(i);
		if (i_s.size() != N) continue;
		string ans_koho = i_s;
		bool ok = true;
		for (int j = 0; j < M; j++) {
			if (ans_koho[s[j]] != c[j]) ok = false;
		}
		if (ok) {
			cout << i << endl;
			return 0;
		}
	}

	cout << -1 << endl;
	return 0;
}