#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> furui(300000, 0);
	furui[0] = furui[1] = 1;
	for (long long int i = 2; i*i <= 300000; i++) {
		if (furui[i] == 0) {
			for (long long int j = 2; i*j < 300000; j++) {
				furui[i*j] = 1;
			}
		}
	}
	vector<long long int> sosu(300000, 0);
	for (long long int i = 2; i < 300000; i++) {
		sosu[i] = sosu[i - 1];
		if (furui[i] == 0) {
			sosu[i]++;
		}
	}
	long long int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		cout << sosu[2 * n] - sosu[n] << endl;
	}
	return 0;
}
