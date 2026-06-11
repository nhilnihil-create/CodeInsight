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
	double l;
	cin >> l;

	long double ans = pow(l / 3, 3);

	printf("%.7llf", ans);

	return 0;
}

//BBBBBBBBBBBBBB
//int main() {
//	string s;
//	cin >> s;
//	int n = s.length();
//	string s1 = s.substr(0, (n - 1) / 2);
//	string _s = s;
//	string _s1 = s1;
//
//	reverse(_s.begin(), _s.end());
//	reverse(_s1.begin(), _s1.end());
//
//	if (s == _s && s1 == _s1) {
//		cout << "Yes" << endl;
//	}
//	else {
//		cout << "No" << endl;
//	}
//
//	return 0;
//}


//AAAAAAAAAAAAAAA
//int main() {
//	int n, m;
//	cin >> n >> m;
//	int ans = 0;
//	if (n >= 2)ans += n * (n - 1) / 2;
//	if (m >= 2)ans += m * (m - 1) / 2;
//	cout << ans << endl;
//
//	return 0;
//}