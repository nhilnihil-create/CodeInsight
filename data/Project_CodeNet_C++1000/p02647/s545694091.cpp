#include<iostream>
using namespace std;
int a[200001], b[200001];
int main() {

	//C
	int n, k;
	cin >> n >> k;
	int i;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
		if (i - a[i] < 0) {
			b[0]++;
		}
		else {
			b[i - a[i]]++;
		}
		if (i + a[i] >= n) {

		}
		else {
			b[i + a[i] + 1]--;
		}
	}
	for (i = 1; i <= n; i++) {
		b[i] = b[i] + b[i - 1];
	}
	int c,flag;
	for (c = 0; c < k; c++) {
		flag = 0;
		for (i = 0; i <= n; i++) {
			a[i] = b[i];
			b[i] = 0;
		}
		for (i = 1; i <= n; i++) {
			if (i - a[i] < 0) {
				b[0]++;
			}
			else {
				b[i - a[i]]++;
			}
			if (i + a[i] >= n) {

			}
			else {
				b[i + a[i] + 1]--;
			}
		}
		for (i = 1; i <= n; i++) {
			b[i] = b[i] + b[i - 1];
		}
		for (i = 1; i <= n; i++) {
			if (a[i] != n) {
				flag = 1;
			}
		}
		if (flag == 0)break;
	}

	for (i = 1; i <= n; i++) {
		cout << a[i] << ' ';
	}






	//B
	/*long long int a, b, v, w, t;
	cin >> a >> v;
	cin >> b >> w;
	cin >> t;
	if (v <= w) {
		cout << "NO" << endl;
		return 0;
	}
	if (abs(a - b) <= t * (v - w)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
	*/

	//A
	/*string s;
	cin >> s;
	int i;
	for (i = 0; i < 3; i++) {
		cout << s[i];
	}
	cout << endl;
	return 0;
	*/
}