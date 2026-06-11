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

int main()
{
	int N;
	cin >> N;
	vector<int> a(N, 0);
	rep(i, N) cin >> a[i];

	int search = 1;
	int cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		if (a[i] == search) {
			search += 1;
			cnt++;
		}
	}

	if (cnt != 0) {
		cout << N - cnt << endl;
	}
	else {
		cout << "-1" << endl;
	}

	return 0;
}
