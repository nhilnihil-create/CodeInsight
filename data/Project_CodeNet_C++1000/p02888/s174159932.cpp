#include <algorithm>
#include <array>
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
#define M_PI 3.14159265358979
#define deg_to_rad(deg) (((deg)/360)*2*M_PI)
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
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
	vector<int> L(N, 0);
	rep(i, N) {
		cin >> L[i];
	}

	sort(L.rbegin(), L.rend());
	int ans = 0;

	for (int i = 0; i < (N - 2); ++i) {
		for (int j = i + 1; j < (N - 1); ++j) {
			for (int k = j + 1; k < N; ++k) {
				if (L[i] < L[j] + L[k]) {
					ans += 1;
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}
