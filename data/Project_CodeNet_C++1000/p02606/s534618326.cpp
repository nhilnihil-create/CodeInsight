#include <bits/stdc++.h>
using namespace std;

int main() {
	int L, R, d;
	cin >> L >> R >> d;
	int total = 0;
	for (int i = L; i < R + 1; i++) {
		if (i % d == 0) {
			total++;
		}
		else {
			continue;
		}
	}
	cout << total << endl;
}

