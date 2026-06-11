#include<iostream>
using namespace std;
long long int cara(long long int x);
int main() {

	//E
	int h, n;
	int a[1000], b[1000];
	int i, j, k;
	cin >> h >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}

	//体力hに対して使用する最小の魔力を求めるDP
	int DP[10001];
	DP[0] = 0;
	int min;
	for (i = 1; i <= h; i++) {
		min = 100000000;
		for (j = 0; j < n; j++) {
			if (a[j] >= i) {
				if (min > b[j]) {
					min = b[j];
				}
			}
			else {
				if (DP[i - a[j]] + b[j] < min) {
					min = DP[i - a[j]] + b[j];
				}
			}
		}
		DP[i] = min;
	}
	cout << DP[h] << endl;
	return 0;

	//D


	/*long long int n;
	cin >> n;
	cout << cara(n) << endl;
	return 0;*/

}
long long int cara(long long int x) {

	int i = 0;
	if (x == 1) {
		return 1;
	}
	else {
		return 1  + 2 * cara((long long int)(x / 2));
	}

}