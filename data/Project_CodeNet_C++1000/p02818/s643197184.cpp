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
	long long a, b, k;
	cin >> a >> b >> k;

	if (k > a) {
		k -= a;
		a = 0;
		b -= k;
		if (b < 0)b = 0;
	}
	else {
		a -= k;
	}

	cout << a << " " << b << endl;

	return 0;
}

//AAAAAAAAAAAAAAAAA
//int main() {
//	string s, t;
//	cin >> s >> t;
//
//	cout << t << s << endl;
//
//	return 0;
//}