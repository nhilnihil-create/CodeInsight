#include<iostream>
using namespace std;

int main(void) {
	int n[1000];
	int sum[1000];
	int count[1000] = {};
	int point;

	for (int i = 1; i <= 1000; i++) {
		cin >> n[i] >> sum[i];
		if ((n[i] == 0) && (sum[i] == 0)) {
			point = i-1;
			break;
		}
	}

	for (int i = 1; i <= 1000; i++) {
		for (int t = 1; t <= n[i]-2; t++) {
			for (int s = t + 1; s <= n[i]-1; s++) {
				for (int u = s + 1; u <= n[i]; u++){
					if ((t + s + u) == sum[i]) {
						count[i]++;
					}
				}
			}
		}
	}

	for (int i = 1; i <= point; i++) {
		cout << count[i] << "\n";
	}
	return 0;
}