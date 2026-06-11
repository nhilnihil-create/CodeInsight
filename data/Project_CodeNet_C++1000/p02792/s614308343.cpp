#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <bitset>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using ll = long long;


int main() {
	ll n;
	cin >> n;
	ll C[10][10];
	rep(i, 10) {
		rep(j, 10) C[i][j] = 0;
	}

	for (int i=1; i<=n; i++) {
		string s = to_string(i);
		int c2 = s.back() - '0';
		int c1 = s[0] - '0';
		C[c1][c2]++;
	}
	ll res = 0;
	rep(i, 10) {
		rep(j, 10) {
			res += C[i][j]*C[j][i];
		}
	}
	cout << res << endl;
}