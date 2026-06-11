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
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main() {
	int k, n;
	cin >> k >> n;
	vector<int> a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	int ans;
	int d = a[n - 1] - a[0];
	if (k / 2 < d)d = k - d;
	for (int i = 1;i < n;i++) {
		if (d < a[i] - a[i - 1])d = a[i] - a[i - 1];
	}
	ans = k - d;
	cout << ans << endl;
	return 0;
}


//BBBBBBBBBBBBBBBBBBB
//int main() {
//	int x;
//	cin >> x;
//	long long _500 = x / 500;
//	long long _5 = x % 500 / 5;
//	long long ans = _500 * 1000 + _5 * 5;
//
//	cout << ans << endl;
//	return 0;
//}


//AAAAAAAAAAAAAAAAAAA
//int main() {
//	string s;
//	cin >> s;
//	if (s[2] == s[3] && s[4] == s[5])cout << "Yes" << endl;
//	else cout << "No" << endl;
//
//	return 0;
//}