#include <iostream>
using namespace std;

#define MAX_N 300000
bool prime[MAX_N];

int main(int argc, char const* argv[])
{
	for (int i = 0; i < MAX_N; i++) {
		prime[i] = true;
	}
	prime[0] = false;
	prime[1] = false;

	for (int i = 0; i < MAX_N; i++) {
		if (prime[i]) {
			for (int j = i + i; j < MAX_N; j+=i) {
				prime[j] = false;
			}
		}
	}

	int n;
	while (cin >> n, n) {
		int cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			cnt += prime[i];
		}
		cout << cnt << endl;
	}
	return 0;
}