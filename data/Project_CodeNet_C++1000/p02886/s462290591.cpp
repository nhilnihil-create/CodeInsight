#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> d(N);
	for (int i = 0; i < N; i++) cin >> d[i];
	int heal = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			heal += d[i] * d[j];
		}
	}
	cout << heal << endl;
	return 0;
}