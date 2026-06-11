#include <iostream>
using namespace std;
int main() {
	long h, w;
	cin >> h >> w;
	if (h == 1 || w == 1) {
		cout << 1 << endl;
		return 0;
	}
	if (h % 2 == 1 && w % 2 == 1) {
		cout << (h * w + 1) / 2 << endl;
	}
	else {
		cout << (h * w) / 2 << endl;
	}
	return 0;
}