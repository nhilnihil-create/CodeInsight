#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;
using ll = long long;

int main() {
	int N;
	string S;
	cin >> N >> S;

	if (N % 2) {
		cout << "No" << endl;
		return 0;
	}

	for (int i = 0; i < N / 2; ++i) {
		if (S[i] != S[N / 2 + i]) {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;
	return 0;
}
