#include<iostream>
#include<algorithm>
using namespace std;
long long int cara(long long int x);
//long long int a[200000];
int main() {


	//B
	int h, n;
	cin >> h >> n;
	int i, a;
	for (i = 0; i < n; i++) {

		cin >> a;
		h = h - a;
		if (h <= 0) {
			cout << "Yes" << endl;
			return 0;
		}


	}
	cout << "No" << endl;
	return 0;
	//C
	/*int n, k;
	int i;
	cin >> n >> k;

	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	long long int sum = 0;
	if (k >= n) {
		cout << 0 << endl;
		return 0;
	}
	for (i = 0; i <= n - k - 1; i++) {
		sum = sum + a[i];
	}
	cout << sum << endl;
	return 0;
	*/

	//E
	/*int h, n;
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
	*/

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