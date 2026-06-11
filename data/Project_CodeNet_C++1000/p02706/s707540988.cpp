#include<bits/stdc++.h>
using namespace std;

int main() {
	int n , m;
	cin >> n >> m;

	int s = 0;
	while (m--) {
		int d;
		cin >> d;
		s += d;
	}

	if (s > n) {
		cout << -1 << endl;
	} else {

		cout << (n - s) << endl;
	}
}