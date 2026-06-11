#include <iostream>
using namespace std;

int main() {
	int A;
	long long B, N;
	cin >> A >> B >> N;

	if (N < B) {
		cout << static_cast<long long>(A * N / B);
	}
	else {
		cout << static_cast<long long>(A * (B - 1) / B);
	}

	return 0;
}