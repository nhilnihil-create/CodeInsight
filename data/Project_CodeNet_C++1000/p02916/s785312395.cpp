#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, A, B, C;
	cin >> N;
	vector<int> vec(N);
	vector<int> plus(N - 1);
	int total = 0;
	for (int i = 0; i < N; i++) {
		cin >> A;
		vec.at(i) = A;
	}
	for (int j = 0; j < N; j++) {
		cin >> B;
		total += B;
	}
	for (int k = 0; k < N - 1; k++) {
		cin >> C;
		plus.at(k) = C;
	}
	for (int l = 0; l < N - 1; l++) {
		if (vec.at(l) + 1 == vec.at(l + 1)) {
			total += plus.at(vec.at(l) - 1);
		}
	}
	cout << total << endl;
}