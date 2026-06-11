#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int K, A, B;
	cin >> K >> A >> B;

	for (int i = A; i <= B; ++i) {
		if (i % K == 0) {
			cout << "OK" << endl;
			return 0;
		}
	}

	cout << "NG" << endl;
	return 0;
}
