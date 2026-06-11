#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[1 << 18], B[1 << 18];
long long Answer = -1;

bool solve(long long lim) {
	for (int i = 0; i <= N; i++) B[i] = 0;
	for (int i = N; i >= 1; i--) {
		B[i] += A[i];
		long long f1 = (B[i] + 1LL) / 2LL;
		long long f2 = B[i];
		if (lim >= f2 - f1) {
			B[i - 1] += f2;
			lim -= (f2 - f1);
		}
		else {
			B[i - 1] += (f1 + lim);
			lim = 0;
		}
	}
	B[0] += A[0];
	if (B[0] >= 2) return false;

	long long sum = 0;
	for (int i = 0; i <= N; i++) sum += B[i];
	Answer = max(Answer, sum);
	return true;
}

int main() {
	cin >> N;
	for (int i = 0; i <= N; i++) cin >> A[i];
	
	long long cl = 0, cr = (1LL << 60), cm;
	for (int i = 0; i < 65; i++) {
		cm = (cl + cr) / 2;
		bool I = solve(cm);
		if (I == true) { cl = cm; }
		else { cr = cm; }
	}

	if (Answer == -1) cout << "-1" << endl;
	else cout << Answer << endl;
	return 0;
}