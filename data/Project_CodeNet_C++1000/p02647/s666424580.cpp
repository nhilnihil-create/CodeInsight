#include <bits/stdc++.h>
using namespace std;

const int nm = 2e5;
int n, k, a[nm], b[nm + 1];
bool flag = 1;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	++k;
	while (--k && flag) {
		fill(b, b + n, 0);
		for (int i = 0; i < n; ++i) {
			++b[max(0, i - a[i])];
			--b[min(n, i + a[i] + 1)];
		}
		for (int i = 0; i < n - 1; ++i)
			b[i + 1] += b[i];
		flag = 0;
		for (int i = 0; i < n; ++i) {
			a[i] = b[i];
			if (a[i] != n)
				flag = 1;
		}
	}
	for (int i = 0; i < n; ++i)
		cout << a[i] << (i < n - 1 ? " " : "\n");
}
