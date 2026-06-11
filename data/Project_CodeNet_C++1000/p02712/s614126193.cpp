#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	long long total = 0;
	for (int i = 1; i < N + 1; i++) {
		if (i % 3 != 0 && i % 5 != 0) {
			total += i;
			}
		else {
			continue;
		}
	}
	cout << total << endl;
}