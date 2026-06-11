#include <bits/stdc++.h>
using namespace std;

int main () {
	string S, T; cin >> S >> T;
	int N = S.size(), M = T.size();
	int ans = 1000;
	for (int i = 0; i <= N - M; i++) {
		int temp = 0;
		for (int j = 0; j < M; j++) {
			if (S[i + j] != T[j]) temp++;
		}
		if (ans > temp) ans = temp;
	}
	cout << ans << endl;
}