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
	int n, k;
	cin >> n >> k;

	vector<int> h(n);
	for (int i = 0;i < n;i++) {
		cin >> h[i];
	}

	sort(h.rbegin(), h.rend());
	long long ans = 0;
	for (int i = k;i < n;i++) {
		ans += h[i];
	}

	cout << ans << endl;
	return 0;
}

//BBBBBBBBBBBBBB
//int main() {
//	int h, n;
//	cin >> h >> n;
//	vector<int> a(n);
//	for (int i = 0;i < n;i++) {
//		cin >> a[i];
//	}
//
//	for (int i = 0;i < n;i++) {
//		h -= a[i];
//		if (h <= 0) {
//			cout << "Yes" << endl;
//			return 0;
//		}
//	}
//
//	cout << "No" << endl;
//
//	return 0;
//}

//AAAAAAAAAAAAA
//int main() {
//	int h,a;
//	cin >> h >> a;
//
//	if (h % a != 0)
//		cout << h / a + 1 << endl;
//	else cout << h / a << endl;
//	
//	return 0;
//}