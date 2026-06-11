#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long mod = 1000000007;
long long N, K, A[100009], B1, B2;

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (A[i] > A[j]) B1++;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i] > A[j]) B2++;
		}
	}
	long long C1 = K;
	long long C2 = K * (K - 1) / 2LL; C2 %= mod;
	cout << (B1*C1 + B2 * C2) % mod << endl;
	return 0;
}
