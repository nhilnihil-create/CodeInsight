#include <algorithm>
#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;

const int N = 5010;
int k, q, d[N];

int main() {
	cin >> k >> q;
	for (int i = 0; i < k; i++)
		cin >> d[i];

	while (q--) {
		long long n, x, m;
		long long res = 0;
		cin >> n >> x >> m;
		long long sum;
		sum = 0;
		for (int i = 0; i < k; i++) {
			sum += d[i] % m;
			if (d[i] % m == 0)
				res++;
		}

		x %= m;
		sum = x + sum * ((n - 1) / k);
		res *= (n - 1) / k;
		for (int i = 0; i < (n - 1) % k; i++) {
			sum += d[i] % m;
			if (d[i] % m == 0)
				res++;
		}
		cout << n - res - 1 - sum / m << endl;
	}

	return 0;
}
