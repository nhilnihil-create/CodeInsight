#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> X(N);
	for (int i = 0; i < N; i++) cin >> X[i];
	int sum = 1000000;
	for (int P = 1; P <= 100; P++) {
		int stamina = 0;
		for (int i = 0; i < N; i++) {
			stamina += (X[i] - P) * (X[i] - P);
		}
		sum = min(sum, stamina);
	}
	cout << sum << endl;
	return 0;
}