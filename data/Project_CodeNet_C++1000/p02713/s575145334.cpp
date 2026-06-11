#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}

int gcd3(int a, int b, int c) {
	return gcd(gcd(a, b), c);
}

int main() {
	int K;
	cin >> K;

	int sum = 0;

	for (int a = 1; a <= K; a++) {
		for (int b = 1; b <= K; b++) {
			for (int c = 1; c <= K; c++) {
				sum += gcd3(a, b, c);
			}
		}
	}

	cout << sum << endl;

	return 0;
}