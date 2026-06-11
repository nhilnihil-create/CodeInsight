#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using LP = pair<ll, ll>;
const double PI = 3.1415926535897932;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

ll md = (ll)1e9 + 7;

int main()
{
	int N;
	cin >> N;
	
	vector<int> mp(101, 0);
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 9; ++j) {
			mp[i * j] = 1;
		}
	}

	if (mp[N] == 1) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}
