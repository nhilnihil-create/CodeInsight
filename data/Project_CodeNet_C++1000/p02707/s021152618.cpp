#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<vector<int>> G(N);
	for (int i = 1; i < N; i++) {
		int A;
		cin >> A;
		A--;
		G[A].push_back(i);
	}
	vector<int> count(N, 0);
	for (int i = 0; i < N; i++) {
		for (int j : G[i]) {
			count[i]++;
		}
	}
	for (int i = 0; i < N; i++) cout << count[i] << endl;
	return 0;
}