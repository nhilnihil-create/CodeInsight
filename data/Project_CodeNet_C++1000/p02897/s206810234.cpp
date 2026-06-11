#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	if (n % 2) {
		cout << (double) (n/2+1) / n << '\n'; 
	} else {
		cout << (double) (n/2) / n << '\n';
	}
	return 0;
}