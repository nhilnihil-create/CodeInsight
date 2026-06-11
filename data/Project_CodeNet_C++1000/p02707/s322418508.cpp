#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, A;
	cin >> N;
	vector<int> vec(N);
	for (int i = 0; i < N - 1; i++) {
		cin >> A;
		vec.at(A - 1)++;
	}
	for (int j = 0; j < N; j++) {
		cout << vec.at(j) << endl;
	}
}