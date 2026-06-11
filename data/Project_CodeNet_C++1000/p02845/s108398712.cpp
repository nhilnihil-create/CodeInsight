#include <iostream>
#include <string>
using namespace std;
#pragma warning (disable: 4996)

int N, A[1 << 18], C[3];
long long sum = 1;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	for (int i = 1; i <= N; i++) {
		long long cnt = 0, id = -1;
		if (A[i] == C[0]) { cnt++; id = 0; }
		if (A[i] == C[1]) { cnt++; id = 1; }
		if (A[i] == C[2]) { cnt++; id = 2; }
		/*if (id == -1) {
			cout << "0" << endl;
			return 0;
		}*/
		sum *= cnt; C[id]++;
		sum %= 1000000007;
	}
	cout << sum << endl;
	return 0;
}
