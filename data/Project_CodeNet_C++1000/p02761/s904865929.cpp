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


int main()
{
	int N, M;
	cin >> N >> M;

	bool judge = true;
	int s[3] = {-1, -1, -1};
	int sm, tm;
	rep(i, M) {
			cin >> sm >> tm;
			if (s[sm - 1] != -1 && s[sm - 1] != tm) {
				judge = false;
				break;
			}
			else {
				s[sm - 1] = tm;
			}
	}

	if (s[0] == 0 && N != 1) judge = false;
	if (s[0] == -1 && N != 1) s[0] = 1;

	int ans = -1;
	if (judge) {
		ans = 0;
		rep(i, N) {
			if (s[i] == -1){
				s[i] = 0;
			}
			ans += s[i] * pow(10, (N - i - 1));
		}
	}

	cout << ans << endl;

	return 0;
} 