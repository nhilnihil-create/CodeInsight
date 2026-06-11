#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

bool isPow(int n) {
	while (n > 1) {
		if (n % 2 == 1) {
			return false;
		}
		n /= 2;
	}
	return true;
}
int main() {
	int N; cin >> N;
	switch (N % 4) {
	case 1:
	{
		if (N == 1) {
			cout << "No" << endl;
		}
		else {
			cout << "Yes" << endl;
			for (int i = 2; i + 1 <= N; i += 2) {
				cout << i << " " << i + 1 << endl;
				cout << i + 1 << " " << 1 << endl;
				cout << 1 << " " << N + i << endl;
				cout << N + i << " " << N + i + 1 << endl;
			}
			cout << N * 2 << " " << N + 1 << endl;
		}
	}
		break;
	case 2:
	{
		if (N == 2) {
			cout << "No" << endl;
		}
		else {
			cout << "Yes" << endl;
			for (int i = 2; i + 1 <= N; i += 2) {
				cout << i << " " << i + 1 << endl;
				cout << i + 1 << " " << 1 << endl;
				cout << 1 << " " << N + i << endl;
				cout << N + i << " " << N + i + 1 << endl;
			}
			cout << N * 2 - 1 << " " << N + 1 << endl;

			cout << N * 2 << " " << N * 2 - 2 << endl;
			cout << (N ^ (N-2) ^ 1) << " " << N << endl;
		}
	}
		break;
	case 3:
	{
		cout << "Yes" << endl;
		for (int i = 2; i + 1 <= N; i += 2) {
			cout << i << " " << i + 1 << endl;
			cout << i + 1 << " " << 1 << endl;
			cout << 1 << " " << N + i << endl;
			cout << N + i << " " << N + i + 1 << endl;
		}
		cout << N * 2 << " " << N + 1 << endl;
	}
		break;
	case 0:
	{
		if (isPow(N)) {
			cout << "No" << endl;
		}
		else {
			cout << "Yes" << endl;
			for (int i = 2; i + 1 <= N; i += 2) {
				cout << i << " " << i + 1 << endl;
				cout << i + 1 << " " << 1 << endl;
				cout << 1 << " " << N + i << endl;
				cout << N + i << " " << N + i + 1 << endl;
			}
			cout << N * 2 - 1 << " " << N + 1 << endl;

			int M = (N ^ (N - 1) ^ 1);

			cout << N << " " << N - 1 << endl;
			cout << M + N << " " << N * 2 << endl;
		}
	}
		break;
	}

	return 0;
}
