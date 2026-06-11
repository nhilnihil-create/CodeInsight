#include <iostream>
using namespace std;

#define MAX 123456
bool isPrime[MAX * 2 + 1];
int primes[MAX * 2 + 1] = {0};

int main() {
	for (int i = 0; i <= MAX * 2; i++) {
		isPrime[i] = true;
	}
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= MAX * 2; i++) {
		if (isPrime[i]) {
			for (int j = 2 * i; j <= MAX * 2; j += i) {
				isPrime[j] = false;
			}
		}
	}

	int p = 0;
	for (int i = 2; i <= MAX * 2; i++) {
		if (isPrime[i]) p++;
		primes[i] = p;
	}

	int n;
	while (cin >> n, n != 0) {
		cout << primes[2 * n] - primes[n] << endl;
	}
}