#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int N;
	cin >> N;
	double denominator = 0;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		denominator += 1.0 / A;
	}
	cout << fixed << setprecision(5) << 1 / denominator << endl;
	return 0;
}