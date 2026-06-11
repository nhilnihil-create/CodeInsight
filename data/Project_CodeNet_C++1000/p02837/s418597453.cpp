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
	vector<int> A(N);
	vector<vector<int>> xy(N, vector<int>(N, -1));

	int x, y;
	rep(i, N){
		cin >> A[i];
		rep(j, A[i]) {
			cin >> x >> y;
			xy[i][x-1] = y;
 		}
	}

	int ans = 0;
	for (int i = 0; i < 1 << N; ++i) {
		int truth_cnt = 0;
		bool check = true;
		vector<int> list(N, 0);

		for (int j = 0; j < N; ++j) {
			if ((i >> j) & 1) {
				list[j] = 1;
				truth_cnt += 1;
			}
		}

		for (int j = 0; j < N; ++j) {
			if (list[j] == 1) {
				for (int k = 0; k < N; ++k) {
					if (xy[j][k] != -1) {
						if (list[k] != xy[j][k]) {
							check = false;
							break;
						}
					}
				}
			}
		}
		
		if (check) {
			ans = max(ans, truth_cnt);
		}
	}

	cout << ans <<endl;
	return 0;
}
