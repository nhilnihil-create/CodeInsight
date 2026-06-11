#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> f(330000, 0);
	vector<int> dd(330000, 0);
	f[0] = f[1] = 1;
	for (int i = 2; i*i <= 330000; i++) {
		for (int j = 2; i*j < 330000; j++) {
			f[i*j] = 1;
		}
	}
	for (int i = 1; i < 330000; i++) {
		dd[i] = dd[i-1];
		if (f[i] == 0) {
			dd[i]++;
		}
	}
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		cout << dd[n * 2] - dd[n] << endl;
	}
	return 0;
}