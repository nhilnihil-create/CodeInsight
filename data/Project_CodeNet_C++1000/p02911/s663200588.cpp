#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K, Q, A;
	cin >> N >> K >> Q;
	vector<int> vec(N);
	int score = Q - K + 1;
	for (int i = 0; i < Q; i++) {
		cin >> A;
		vec.at(A - 1)++;
	}
	for (int j = 0; j < N; j++) {
		if (vec.at(j) >= score) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}
