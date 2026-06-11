#include <bits/stdc++.h>
using namespace std;

int main() {
	long long N, X, a;
	cin >> N;
	long long total = 0;
	vector<int> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> X;
		vec.at(i) = X;
		total += X;
	}
	a = total % N;
	if (a <= N / 2) {
		a = total / N;
	}
	else {
		a = total / N + 1;
	}
	total = 0;
	for (int j = 0; j < N; j++) {
		total += (a - vec.at(j)) * (a - vec.at(j));
	}
	cout << total << endl;
}