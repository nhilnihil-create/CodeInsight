#include <iostream>

using namespace std;

int main() {
	int L, R, d;
	cin >> L >> R >> d;
	int res = 0;

	for (int i = 0; i <= 100; ++i) {
		if (d*i < L)
			continue;
		else if (d*i <= R)
			res++;
		else
			break;
	}
	cout << res << endl;
	return 0;
}
