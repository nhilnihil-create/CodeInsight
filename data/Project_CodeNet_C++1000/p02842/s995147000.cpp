#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i <= N; ++i) {
		int num = i * 108;
		num /= 100;
		if (N == num) {
			cout << i << endl;
			return 0;
		}
	}
	cout << ":(" << endl;
	return 0;
}