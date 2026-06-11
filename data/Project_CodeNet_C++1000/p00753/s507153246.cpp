#include <iostream>
#include <cstring>
using namespace std;
int prime[300001];

int main() {
	memset(prime, -1, sizeof(prime));
	prime[0] = prime[1] = 0;
	for (int i = 2; i <= 150000; i++) {
		if (prime[i] == 0) continue;
		for (int j = 2; i*j <= 300000; j++) {
			prime[i*j] = 0;
		}
	}
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		int count = 0;
		for (int i = n+1; i <= 2*n; i++) {
			if (prime[i] == 0) continue;
			count++;
		}
		cout << count <<endl;
	}
	return 0;
}