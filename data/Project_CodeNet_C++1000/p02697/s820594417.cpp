#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
	int N, M; cin >> N >> M;
	if (N & 1) {
		for (int i = 1; i <= M; ++i)
			cout << i << " " << (N - i) << endl;
	}
	else {
		for (int i = 1; i <= M; ++i) {
			int tmp = N - i;
			if (N - 2 * i <= N / 2) --tmp;
			cout << i << " " << tmp << endl;
		}
	}
	return 0;
}
