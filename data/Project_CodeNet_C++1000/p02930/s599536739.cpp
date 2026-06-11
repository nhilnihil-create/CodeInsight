#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			int b;
			for (b = 0; !((i ^ j) & (1 << b)); b++) { }
			cout << b+1 << " \n"[j == N-1];
		}
	}

	return 0;
}
