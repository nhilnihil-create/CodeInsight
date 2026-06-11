#include <iostream>
using namespace std;
using ll = long long;

int main() {
	int A, B, C, K;
	cin >> A >> B >> C >> K;
	int cnt = 0;
	while (A >= B) {
		B *= 2;
		if (++cnt > K) {
			cout << "No" << endl;
			return 0;
		}
	}
	while (B >= C) {
		C *= 2;
		if (++cnt > K) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
