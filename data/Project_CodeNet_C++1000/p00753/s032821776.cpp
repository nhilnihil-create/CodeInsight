#include <iostream>
#include <algorithm>
using namespace std;
bool isPrime[250000];
int main() {
	fill(isPrime, isPrime + 250000, true);
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 0; i * i <= 250000; i++) {
		if (isPrime[i]) {
			for (int j = (i << 1); j < 250000; j += i) {
				isPrime[j] = false;
			}
		}
	}
	int n;
	while (cin >> n, n) {
		int count = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (isPrime[i]) count++;
		}
		cout << count << endl;
	}
	return 0;
}