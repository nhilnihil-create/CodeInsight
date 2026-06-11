#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> s(m);
	vector<int> c(m);
	vector<int> a(n);
	for (int i = 0;i < n;i++) {
		a[i] = -1;
	}

	for (int i = 0;i < m;i++) {
		cin >> s[i] >> c[i];
	}

	for (int i = 0;i < m;i++) {
		if (a[s[i] - 1] == -1) {
			a[s[i] - 1] = c[i];
		}
		else if (a[s[i] - 1] != c[i]) {
			cout << -1 << endl;
			return 0;
		}
	}

	if (a[0] == 0) {
		if (n == 1) 
			cout << 0 << endl;
		else cout << -1 << endl;

		return 0;
	}

	int ans = 0;

	for (int i = 0;i < n;i++) {
		if (a[i] == -1) {
			if (i == 0 && n > 1) {
				ans += 1 * pow(10, n - 1);
			}
		}
		else {
			ans += a[i] * pow(10, n - 1 - i);
		}
	
	}

	cout << ans << endl;

	return 0;
}

//BBBBBBBBBBBBBBB
//int main() {
//	int a[3][3];
//	for (int i = 0;i < 3;i++) {
//		cin >> a[i][0] >> a[i][1] >> a[i][2];
//	}
//
//	int n;
//	cin >> n;
//	vector<int> b(n);
//
//	for (int i = 0;i < n;i++) {
//		cin >> b[i];
//	}
//
//	for (int i = 0;i < n;i++) {		
//		for (int j = 0;j < 3;j++) {
//			for (int k = 0;k < 3;k++) {
//				if (b[i] == a[j][k]) {
//					a[j][k] = 0;
//				}
//			}
//		}
//	}
//
//	for (int i = 0;i < 3;i++) {
//		if (a[i][0] == 0 && a[i][1] == 0 && a[i][2] == 0) {
//			cout << "Yes" << endl;
//			return 0;
//		}
//	}
//
//	for (int i = 0;i < 3;i++) {
//		if (a[0][i] == 0 && a[1][i] == 0 && a[2][i] == 0) {
//			cout << "Yes" << endl;
//			return 0;
//		}
//	}
//
//	if (a[0][0] == 0 && a[1][1] == 0 && a[2][2] == 0) {
//		cout << "Yes" << endl;
//		return 0;
//	}
//
//	if (a[0][2] == 0 && a[1][1] == 0 && a[2][0] == 0) {
//		cout << "Yes" << endl;
//		return 0;
//	}
//
//	cout << "No" << endl;
//
//	return 0;
//}


//AAAAAAAAAAAA
//int main() {
//	int n;
//	cin >> n;
//
//	cout << n / 2 + n % 2 << endl;
//
//	return 0;
//}