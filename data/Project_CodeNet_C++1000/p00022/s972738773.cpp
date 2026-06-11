#include<iostream>
using namespace std;
int a[5000];
int b[5000][5000];
int main() {
	int n;
	while (cin >> n&&n != 0) {
		int sum = -100000;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i == 0) {
				b[0][i] = a[i];
				if (sum < b[0][i])
					sum = b[0][i];
			}
			else {
				b[0][i] = b[0][i - 1] + a[i];
				if (sum < b[0][i])
					sum = b[0][i];
			}
		}
		
		for (int j = 1; j < n; j++) {
			for (int i = j; i < n ; i++) {
				b[j][i] = b[j - 1][i] - a[j - 1];
				if (sum < b[j][i])
					sum = b[j][i];
			}
		}
		cout << sum << endl;
	}
}