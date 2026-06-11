#include <iostream>

using namespace std;
using ll = long long;

int main() {
	int A, B;
	cin >> A >> B;

	for (int i = 1; i <= 3; ++i) {
		if (i != A && i != B) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
