#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool uin(T& a, T b) { return a > b ? (a = b, true) : false; }
template <class T>
inline bool uax(T& a, T b) { return a < b ? (a = b, true) : false; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	string S;
	cin >> S;
	vector<int> A(N);
	for (int i = 0; i < N; ++i)
		A[i] = (int)(S[i] - '1');

	bool one = false;
	for (int i = 0; i < N; ++i) one |= (A[i] == 1);

	if (one) {
		int ans = 0;
		for (int i = 0; i < N; ++i)
			if ((i & (N - 1)) == i) ans ^= (A[i] & 1);
		cout << ans << '\n';
		return 0;
	}

	int ans = 0;
	for (int i = 0; i < N; ++i)
		if ((i & (N - 1)) == i) ans ^= (A[i] & 2);
	cout << ans << '\n';
}