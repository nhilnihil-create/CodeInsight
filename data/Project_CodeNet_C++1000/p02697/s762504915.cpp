#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	if(m % 2 == 0) {
		int st = 1;
		for(int i = m - 1; i > 0; i -= 2) {
			cout << st << " " << st + i << '\n';
			++st;
		}
		st = m + 1;
		for(int i = m; i > 0; i -= 2) {
			cout << st << " " << st + i << '\n';
			++st;
		}
	} else {
		int st = 1;
		for(int i = m; i > 0; i -= 2) {
			cout << st << " " << st + i << '\n';
			++st;
		}
		st = m + 2;
		for(int i = m - 1; i > 0; i -= 2) {
			cout << st << " " << st + i << '\n';
			++st;
		}
	}
	return 0;
}