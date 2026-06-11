#include <iostream>

using namespace std;

int main(void) {
	int n, num[101] = {0};
	int mode[100] = {0};

	while (cin >> n) {
		num[n]++;
	}
	for (int i = 1; i <= 101; i++) {
		if (num[i] != 0) {
			if (num[i] == num[mode[0]]) {
				for (int j = 0; j < 100; j++) {
					if (mode[j] == 0) {
						mode[j] = i;
						break;
					}
				}
			}
			else if (num[i] > num[mode[0]]) {
				for (int j = 0; j < 100; j++) {
					mode[j] = 0;
				}
				mode[0] = i;
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		cout << mode[i] << endl;
		if (mode[i + 1] == 0) {
			break;
		}
	}
}