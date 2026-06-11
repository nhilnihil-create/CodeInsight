#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int a[100000 + 1];
int s[100000 + 1];

int main() {

	int n, k;
	int i, j, l;
	int sum = 0, asus = 0;

	while (true) {

		memset(s, 0, sizeof(s));
		memset(a, 0, sizeof(a));

		cin >> n >> k;
		if (n == 0 && k == 0) return 0;

		for (i = 0; i < n; ++i) cin >> a[i];

		for (i = 0; i < n-k; ++i) {
			for (j = 0; j < k; ++j) {

				sum += a[i + j];
			}
			asus = max(asus, sum);
			sum = 0;
		}

		cout << asus << endl;
	}
}
