#include "bits/stdc++.h"
using namespace std;

class eratosthenes {
private:
	long long int x;
	int nsqrt;
	int ans = 0;
	vector<bool> sieve;
public:
	eratosthenes(long long int n) {
		x = n;

		nsqrt = sqrtl(x);
		sieve.reserve(nsqrt);

		sieve[0] = false;
		sieve[1] = false;
		for (int i = 2; i <= nsqrt; i++) sieve[i] = true;

		for (int i = 1; i <= nsqrt; i++) {
			if (sieve[i] == false) continue;

			int fac = 0;
			while (x % i == 0) {
				x /= i;
				fac++;
			}

			for (int j = 1; j <= fac; j++) {
				if (fac - j >= 0) {
					fac -= j;
					ans++;
				}
			}

			for (int j = i + i; j <= nsqrt; j += i) sieve[j] = false;
		}
		if (x != 1) ans++;
	}
	void print() {
		cout << ans << endl;
	}
};

int main() {
	long long int n;
	cin >> n;
	eratosthenes e(n);
	e.print();
}