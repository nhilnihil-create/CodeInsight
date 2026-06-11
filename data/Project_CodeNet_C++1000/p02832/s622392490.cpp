#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	int n;
	cin >> n;
	int current = 1;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == current) {
			current++;
		}
	}
	if (current == 1) {
		cout << "-1\n";
		return 0;
	}
	cout << n - (current - 1) << '\n';
	return 0;
}
