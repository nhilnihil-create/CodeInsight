#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(1 + N);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	int cnt = 0;
	for (int i = N; i >= 1; --i) {
		for (int j = i * 2; j <= N; j += i) {
			A[i] ^= A[j];
		}
		cnt += A[i];
	}
	cout << cnt << endl;
	for (int i = 1; i <= N; ++i) {
		if (A[i] == 1) {
			cout << i << ((--cnt) == 0 ? '\n' : ' ');
		}
	}
	return 0;
}