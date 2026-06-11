#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, B, C, K;
	cin >> A >> B >> C >> K;
	for (int i = 0; i < K; i++) {
		if (A >= B) {
			B *= 2;
		}
		else if (B >= C) {
			C *= 2;
		}
	}
	if (A < B && B < C) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
