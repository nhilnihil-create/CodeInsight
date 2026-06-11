#include <iostream>
using namespace std;

string S;
long long N, P;
long long R[1 << 18], power[1 << 18];
long long cnt[1 << 18];

int main() {
	cin >> N >> P >> S;
	
	if (P == 2 || P == 5) {
		long long ans = 0;
		for (int i = 0; i < N; i++) {
			if ((S[i] - '0') % P == 0) ans += (i + 1);
		}
		cout << ans << endl;
	}
	else {
		power[0] = 1;
		for (int i = 1; i <= N; i++) power[i] = (10LL * power[i - 1]) % P;
		for (int i = N - 1; i >= 0; i--) {
			R[i] = (R[i + 1] + (S[i] - '0') * power[N - i - 1]) % P;
		}
		for (int i = 0; i <= N; i++) cnt[R[i]]++;

		long long ans = 0;
		for (int i = 0; i < P; i++) ans += 1LL * cnt[i] * (cnt[i] - 1) / 2LL;
		cout << ans << endl;
	}
	return 0;
}