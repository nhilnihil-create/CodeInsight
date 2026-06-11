#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int K, X;
	cin >> K >> X;
	int left = X - K + 1;
	int right = X + K - 1;
	for (int i = left; i <= right; i++) {
		cout << i << " ";
	}
	return 0;
}