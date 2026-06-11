#include<iostream>

using namespace std;

int get2(int a) {
	int cnt = 0;
	while (a >= (1 << cnt))cnt++;
	return cnt - 1;
}

int main() {
	int N;

	cin >> N;

	if (N == (1 << get2(N))) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;

	cout << 1 << " " << 2 << endl;
	cout << 2 << " " << 3 << endl;
	cout << 3 << " " << N + 1 << endl;
	cout << N + 1 << " " << N + 2 << endl;
	cout << N + 2 << " " << N + 3 << endl;

	for (int i = 4; i < N; i += 2) {
		cout << i + 1 << " " << i << endl;
		cout << i << " " << 1 << endl;
		cout << 1 << " " << N + i + 1 << endl;
		cout << N + i + 1 << " " << N + i << endl;

	}
	
	if (N % 2 == 0) {
		cout << N << " " << N + ((1 << get2(N)) + 1) << endl;
		cout << (N ^ (1 << get2(N))) << " " << N + N << endl;
	}

	return 0;
}