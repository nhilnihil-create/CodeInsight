#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	for (int i = 1; i <= 1000; i++) {
		int aa = (double)i * 0.08;
		int bb = (double)i * 0.10;
		if (aa==a && bb==b) {
			cout << i << endl;
			return 0;
		}
	}

	cout << -1 << endl;
}