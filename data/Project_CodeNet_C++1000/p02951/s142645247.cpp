#include <iostream>

using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	int y1_nokori = A - B;

	if (y1_nokori <= C) {
		cout << C - y1_nokori << endl;
	}
	else {
		cout << 0 << endl;
	}

}