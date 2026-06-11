#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;

	int pay = 0;

	for (int i = 0; i < 10; i++) {
		if (N - 1000 * (i + 1) <= 0) {
			pay = 1000 * (i + 1);
			break;
		}
	}

	cout << pay - N << endl;
}