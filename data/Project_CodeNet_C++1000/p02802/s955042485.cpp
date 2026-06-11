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

	vector<int> p(m);
	vector<string> s(m);
	for (int i = 0;i < m;i++) {
		cin >> p[i] >> s[i];
	}

	vector<int> seikai(n + 1);
	int ac = 0;
	int pena = 0;
	vector<int> wa(n + 1);

	for (int i = 0;i < m;i++) {
		if (seikai[p[i]] == 0) {
			if (s[i] == "WA") {
				wa[p[i]]++;
			}
			else {
				seikai[p[i]] = 1;
				ac++;
				pena += wa[p[i]];
			}
		}
	}

	cout << ac << " " << pena << endl;

	return 0;
}

//BBBBBBBBBBBBBBBBBB
//int main() {
//	int n, k, m;
//	cin >> n >> k >> m;
//
//	int sum = 0;
//	vector<int> a(n);
//	for (int i = 0;i < n - 1;i++) {
//		cin >> a[i];
//		sum += a[i];
//	}
//
//	if (n * m - sum - k > 0) {
//		cout << -1 << endl;
//	}
//	else {
//		cout << max(n * m - sum,0) << endl;
//	}
//
//	return 0;
//}

//AAAAAAAAAAAAAAAAA
//int main() {
//	char c;
//	cin >> c;
//	cout << (char)(c + 1) << endl;
//
//	return 0;
//}