#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> A(N);
	int xall = 0;
	for (int& e : A) {
		cin >> e;
		xall ^= e;
	}
	for (int i = 0; i < N; ++i) {
		cout << (xall^A[i]) << " ";
	}
	cout << endl;
}