#include <bits/stdc++.h>
using namespace std;

int main() {
	int N ,W, T;
	cin >> N;
	int total = 0;
	int total2 = 0;
	vector<int> vec(N);
	vector<int> absolute(N);
	for (int i = 0; i < N; i++) {
		cin >> W;
		vec.at(i) = W;
	}
	for (int j = 0; j < N; j++) {
		total = 0;
		total2 = 0;
		for (int k = 0; k < j + 1; k++) {
			total += vec.at(k);
		}
		for (int l = j + 1; l < N; l++) {
			total2 += vec.at(l);
		}
		absolute.at(j) = abs(total - total2);
	}
	sort(absolute.begin(), absolute.end());
	cout << absolute.at(0) << endl;
}