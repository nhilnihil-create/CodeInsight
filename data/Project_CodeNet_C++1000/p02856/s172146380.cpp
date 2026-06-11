#include <iostream>
using namespace std;

long long M, A[1 << 18], B[1 << 18];
long long V1, V2;

int main() {
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		V1 += B[i];
		V2 += 1LL * A[i] * B[i];
	}
	cout << ((V2 - 1LL) / 9LL) + (V1 - 1LL) << endl;
	return 0;
}