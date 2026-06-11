#include<bits/stdc++.h>
using namespace std;

int N;
string S;

void solve() {
	S.push_back('.');
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if (S[i] != S[i + 1]) {
			ans++;
		}
	}
	cout << ans << endl;
}

int main() {
	cin >> N >> S;
	solve();

	return 0;
}