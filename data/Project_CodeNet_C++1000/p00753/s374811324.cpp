#include <iostream>

#define MAX_N 123456

using namespace std;

int main() {
	int prime[MAX_N*2+1];
	fill(&prime[0], &prime[0]+MAX_N*2+1, 1);

	for (int i = 2; i <= MAX_N*2; ++i) {
		for (int j = i*2; j <= MAX_N*2; j += i) {
			prime[j] = 0;
		}
	}

	for (int i = 0; i < MAX_N*2; ++i) {
		prime[i+1] += prime[i];
	}

	int n;
	while ( cin >> n, n ) {
		cout << prime[2*n] - prime[n] << endl;
	}
}