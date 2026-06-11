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

void print(vector<int> v) {
	for_each(v.begin(), v.end(), [](int x) {
		cout << x << " ";
		});
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	vector<int> q(n);
	for (int i = 0;i < n;i++) {
		cin >> p[i];
	}

	for (int i = 0;i < n;i++) {
		cin >> q[i];
	}

	vector<int> v(n);
	for (int i = 0;i < n;i++) {
		v[i] = i + 1;
	}

	int pn = 0, qn = 0;
	int count = 0;
	do {
		count++;
		if (v == p) {
			pn = count;
		}
		if (v == q) {
			qn = count;
		}
	} while (next_permutation(v.begin(), v.end()));
	
	cout << abs(pn - qn) << endl;
	return 0;
}


//BBBBBBBBBBBBBBBBBB
//int main() {
//	int n;
//	string s;
//	cin >> n >> s;
//
//	int ans = 0;
//	for (int i = 0;i < n - 2;i++) {
//		if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')ans++;
//	}
//
//	cout << ans << endl;
//
//	return 0;
//}

//AAAAAAAAAAAAAAAAA
//int main() {
//	int k, x;
//	cin >> k >> x;
//
//	if (k * 500 >= x) cout << "Yes" << endl;
//	else cout << "No" << endl;
//
//	return 0;
//}
