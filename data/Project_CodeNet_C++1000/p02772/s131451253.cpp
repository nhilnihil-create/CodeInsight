#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, A;
	cin >> N;
	int total = 0;
	for (int i = 0; i < N; i++) {
		cin >> A;
		if (A % 2 == 0 && A % 3 == 0) {
			total++;
		}
		else if (A % 2 == 0 && A % 5 == 0) {
			total++;
		}
		else if (A % 2 != 0) {
			total++;
		}
		else {
			continue;
		}
	}
	if (total == N) {
		cout << "APPROVED" << endl;
	}
	else {
		cout << "DENIED" << endl;
	}
}