#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	int digit = 0;
	while (N != 0) {
		N /= K;
		digit++;
	}
	cout << digit << endl;
	return 0;
}