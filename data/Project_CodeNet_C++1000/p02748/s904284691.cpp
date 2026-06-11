#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int A, B, M;
	cin >> A >> B >> M;
	vector<int> a(A), b(B);
	int min_a, min_b;
	for (int i = 0; i < A; i++) {
		cin >> a.at(i);
		if (i == 0) {
			min_a = a.at(i);
		} else {
			if (min_a > a.at(i)) {
				min_a = a.at(i);
			}
		}
	}
	for (int i = 0; i < B; i++) {
		cin >> b.at(i);
		if (i == 0) {
			min_b = b.at(i);
		} else {
			if (min_b > b.at(i)) {
				min_b = b.at(i);
			}
		}
	}

	int min_cost = min_a + min_b;
	for (int i = 0; i < M; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		int cost = a.at(x - 1) + b.at(y - 1) - c;
		if (min_cost > cost) {
			min_cost = cost;
		}
	}

	cout << min_cost << endl;
}