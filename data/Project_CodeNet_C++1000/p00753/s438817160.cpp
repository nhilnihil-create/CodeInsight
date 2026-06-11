#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

bool is_prime(int n) {
	if (n < 2) {
			return false;
	}
	if (n==2||n==3) {
		return true;
	}
	for (int i = 3; i < n; i = i+2) {
		if (n%i==0) {
			return false;
		}
	}
	return true;
}

int main(void) {
	int N = 123456*2;
	int n;
	cin >> n;

	std::vector<bool> prime(N);
	for (int i = 0; i < N+2; i++) {
		prime[i] = true;
	}
	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i <= sqrt(N); i++) {
		if (is_prime(i)) {
			for (int j = 2; i*j < N+2; j++) {
				prime[i*j] = false;
			}
		}
	}
	
	while (n!=0) {
		int count = 0;
		for (int i = n+1; i < (2*n)+1; i++) {
			if (prime[i]) {
				count++;
			}
		}
		cout << count << endl;

		cin >> n;
	}

	return 0;
}