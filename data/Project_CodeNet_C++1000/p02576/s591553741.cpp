#include <iostream>
using namespace std;

int main() {
	int N, X, T;
	cin >> N >> X >> T;
	int A = N / X;

	if (N % X == 0) {
		cout << A * T;
	}
	else {
		cout << (A + 1) * T;
	}

	return 0;
}