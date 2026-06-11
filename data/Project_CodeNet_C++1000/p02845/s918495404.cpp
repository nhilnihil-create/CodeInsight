
// E - Colorful Hats 2

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
const ll MOD = 1e9 + 7;

int A[100001];
int hat[100001][3]; // hat[i][j]: i番目の人までの帽子のかぶり方（jは色の違いを表すが色は任意）

int main() {
	int N;
	cin >> N;

	for (int i=1; i<=N; i++) {
		cin >> A[i];
	}

	hat[0][0] = 0;
	hat[0][1] = 0;
	hat[0][2] = 0;

	for (int i=1; i<=N; i++) {
		bool impossible = true;

		for (int j=0; j<3; j++) {
			hat[i][j] = hat[i-1][j];
		}

		for (int j=0; j<3; j++) {
			if (hat[i-1][j] == A[i]) {
				hat[i][j]++;
				impossible = false;
				break;
			}
		}

		if (impossible) {
			cout << 0 << endl;
			return 0;
		}
	}

	/*
	// **** debug ****
	for (int i=0; i<=N; i++) {
		for (int j=0; j<3; j++) {
			cout << " " << hat[i][j];
		}
		cout << endl;
	}
	*/

	ll ans = 1;
	for (int i=1; i<=N; i++) {
		int cnt = 0;
		for (int j=0; j<3; j++) {
			if (hat[i-1][j] == A[i]) cnt++;
		}
		ans = (ans * cnt) % MOD;
	}

	cout << ans << endl;

	return 0;
}