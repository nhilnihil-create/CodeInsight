#include <iostream>
using namespace std;

int main() {
	int X;
	cin >> X;
	int kyu[] = {2000, 1800, 1600, 1400, 1200, 1000, 800, 600, 400};

	for (int i = 0; i < 9; i++) {
		if (X >= kyu[i]) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}
