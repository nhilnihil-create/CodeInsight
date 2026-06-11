// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
	int a[2], ans = 0;
	for (int i = 0; i < 2; ++i) {
		cin >> a[i];
		switch (a[i]) {
		case 1:
			ans += 300000;
			break;
		case 2:
			ans += 200000;
			break;
		case 3:
			ans += 100000;
			break;
		}
	}
	if (a[0] == 1 && a[1] == 1) {
		ans += 400000;
	}
	cout << ans << endl;
	return 0;
}
