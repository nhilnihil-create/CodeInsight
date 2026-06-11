#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int N, D[1 << 18];
int cnt[1 << 18];
long long mod = 998244353;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> D[i];
		cnt[D[i]]++;
	}
	if (cnt[0] != 1 || D[1] != 0) {
		cout << "0" << endl;
		return 0;
	}

	long long ans = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= cnt[i]; j++) { ans *= cnt[i - 1]; ans %= mod; }
	}
	cout << ans << endl;
	return 0;
}