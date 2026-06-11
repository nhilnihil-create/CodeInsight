#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 262144
#define REP(i,n) for(long long i = 0;i < n;++i)
int geko[300000] = {};
int main() {
	int n;
	cin >> n;
	for (int q = 0; q < 20; ++q) {
		if (1 << q == n) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	if (n % 2 == 1) {
		cout << "1 2" << endl;
		cout << "2 3" << endl;
		cout << "3 " << n + 1 << endl;
		cout << n + 1 << " " << n + 2 << endl;
		cout << n + 2 << " " << n + 3 << endl;
		for (int q = 4; q < n; q += 2) {
			cout << q << " " << n + 1 << endl;
			cout << q + 1 << " " << q << endl;
			cout << n + q + 1 << " " << n + 1 << endl;
			cout << n + q << " " << n + q + 1 << endl;
		}
	}
	else {
		cout << "1 2" << endl;
		cout << "2 3" << endl;
		cout << "3 " << n + 1 << endl;
		cout << n + 1 << " " << n + 2 << endl;
		cout << n + 2 << " " << n + 3 << endl;
		geko[2] = n + 2;
		geko[3] = 3;
		for (int q = 4; q < n-1; q += 2) {
			cout << q << " " << n + 1 << endl;
			geko[q] = q;
			cout << q + 1 << " " << q << endl;
			cout << n + q + 1 << " " << n + 1 << endl;
			geko[q + 1] = n + q + 1;
			cout << n + q << " " << n + q + 1 << endl;
		}
		for (long long q = 2; q <= n - 1; ++q) {
			long long tea = (n ^ q);
			tea ^= 1;
			if (tea < n&&tea >= 2 && tea != q) {
				cout << n << " " << geko[q] << endl;
				cout << 2 * n << " " << geko[tea] << endl;
				return 0;
			}
		}
	}
}