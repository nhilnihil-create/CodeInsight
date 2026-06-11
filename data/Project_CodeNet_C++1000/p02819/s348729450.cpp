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
	int x;
	cin >> x;
	vector<int> sosuu(100004);

	for (int i = 2;i <= 100003;i++) {
		sosuu[i] = 0;
	}

	for (int i = 2;i <= 100003;i++) {
		if (sosuu[i] == 0) {
			for (int j = i*2;j <= 100003;j = j + i) {
				sosuu[j]++;
			}
		}
	}

	for (int i = x;i <= 100003;i++) {
		if (sosuu[i] == 0) {
			cout << i << endl;
			return 0;
		}
	}

	return 0;
}

//BBBBBBBBBBBBBBBBBB
//int main() {
//	long long a, b, k;
//	cin >> a >> b >> k;
//
//	if (k > a) {
//		k -= a;
//		a = 0;
//		b -= k;
//		if (b < 0)b = 0;
//	}
//	else {
//		a -= k;
//	}
//
//	cout << a << " " << b << endl;
//
//	return 0;
//}

//AAAAAAAAAAAAAAAAA
//int main() {
//	string s, t;
//	cin >> s >> t;
//
//	cout << t << s << endl;
//
//	return 0;
//}