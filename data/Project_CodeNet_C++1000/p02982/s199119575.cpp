#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int N, D;
	cin >> N >> D;
	vector<vector<int>> X(N, vector<int>(D));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < D; j++) {
			cin >> X[i][j];
		}
	}
	int count = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			double dist;
			int sum = 0;
			for (int k = 0; k < D; k++) {
				sum += (X[i][k] - X[j][k]) * (X[i][k] - X[j][k]);
				dist = sqrt(sum);
			}
			if (floor(dist) == dist) count++;
		}
	}
	cout << count << endl;
	return 0;
}