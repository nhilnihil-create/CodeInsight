#include <iostream>
using namespace std;

typedef long long LL;
const LL B = 1000000007LL;


LL f(LL N, LL M) {
	return (M * (N - M + 1) + 1) % B;
}


int main() {
	LL N, K;
	cin >> N >> K;

	LL cnt = 0;
	for (LL M = K; M <= N + 1; ++M) {
		cnt += f(N, M);
		cnt = cnt % B;
	}

	cout << cnt << endl;

	return 0;
}
