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
	int a, b;
	cin >> a >> b;
	int ans = -1;
	for (int i = 1;i <= 1000;i++) {
		if ((int)(i * 0.08) == a && (int)(i * 0.1) == b) {
			ans = i;
			break;
		}
	}
	cout << ans << endl;

	return 0;
}

//BBBBBBBBBBBBBBBBB
//int main() {
//	long long n, a, b;
//	cin >> n >> a >> b;
//	long long ans = 0;
//	long long tmp = a * (n / (a + b));
//	if (n % (a + b) < a) {
//		ans = tmp + n % (a + b);
//	}
//	else ans = tmp + a;
//
//	cout << ans << endl;
//
//	return 0;
//}

//AAAAAAAAAAAAAAAAA
//int main() {
//	string s;
//	cin >> s;
//
//	if (s[0] != s[1] || s[1] != s[2] || s[2] != s[0])
//		cout << "Yes" << endl;
//	else
//		cout << "No" << endl;
//
//	return 0;
//}