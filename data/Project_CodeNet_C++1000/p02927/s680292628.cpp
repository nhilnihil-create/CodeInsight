#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;

int main() {
	int M, D;
	cin >> M >> D;

	int days=0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < D; j++) {
			if ((j + 1) / 10 > 1 && (j + 1) % 10 > 1 && i + 1 == ((j + 1) / 10) * ((j + 1) % 10)) {
				days++;
			}
		}
	}

	cout << days << endl;
	return 0;
}