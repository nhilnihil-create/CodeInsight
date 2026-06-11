#include <bits/stdc++.h>

using namespace std;

int main() {

	long long h, w;
	cin >> h >> w;

	if (h == 1 || w==1) {
		cout << 1 << endl;
		return 0;
	}

	if (h % 2 == 0 && w % 2 == 0) {
		cout << h * w / 2 << endl;
		return 0;
	}
	if (h % 2 == 0) {
		cout << h * (w - 1) / 2 + h / 2 << endl;
		return 0;
	}
	if (w % 2 == 0) {
		cout << (h - 1) * w / 2 + w / 2 << endl;
		return 0;
	}

	cout << (h - 1)*(w - 1) / 2 + (h + 1) / 2 + (w + 1) / 2 -1 << endl;

	return 0;
}