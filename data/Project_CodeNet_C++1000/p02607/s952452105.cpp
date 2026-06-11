#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, a;
	cin >> N;
	int total = 0;
	vector<int> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> a;
		vec.at(i) = a;
	}
	for (int j = 0; j < N; j++) {
		if (vec.at(j) % 2 == 1 && j % 2 == 0) {
			total++;
		}
		else {
			continue;
		}
	}
	cout << total << endl;
}
