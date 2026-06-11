#include<iostream>
using namespace std;
#define REP(i, a, n) for(int i=a; i<n; i++)

bool isPrime[250000];
void getPrime() {
	isPrime[0] = isPrime[1] = false;
	REP(i, 2, 250000) isPrime[i] = true;

	for (int i = 2; i*i < 250000; i++) {
		for (int j = 2 * i; j < 250000; j += i) {
			isPrime[j] = false;
		}
	}
	return;
}
int main() {
	int n;
	getPrime();

	while (cin >> n, n) {
		int cnt = 0;
		REP(i, n + 1, 2 * n + 1) {
			if (isPrime[i]) cnt++;
		}

		cout << cnt << endl;
	}
	return 0;
}