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
	int n;
	cin >> n;
	map<string,int> m;
	for (int i = 0;i < n;i++) {
		string tmp;
		cin >> tmp;
		m[tmp]++;
	}

	//sort(m.rbegin(), m.rend());
	int max = -1;

	for (auto x : m) {
		if (max < m[x.first]) {
			max = x.second;
		}
	}

	for (auto x : m) {
		if (max == x.second) {
			cout << x.first << endl;
		}
	}

	return 0;
}

//BBBBBBBBBBBB
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0;i < n;i++) {
//		cin >> a[i];
//	}
//
//	for (int i = 0;i < n;i++) {
//		if (a[i] % 2 == 0) {
//			if (a[i] % 3 == 0 || a[i] % 5 == 0) {
//			}
//			else {
//				cout << "DENIED" << endl;
//				return 0;
//			}
//		}
//	}
//
//	cout << "APPROVED" << endl;
//	return 0;
//}

//AAAAAAAAAAAAAAAA
//int main() {
//	int a, b, c;
//	cin >> a >> b >> c;
//
//	if (a != b && b != c && c != a) {
//		cout << "No" << endl;
//	}
//	else if (a == b && b == c) {
//		cout << "No" << endl;
//	}
//	else cout << "Yes" << endl;
//
//	return 0;
//}