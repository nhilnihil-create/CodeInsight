#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int M, D;
	cin >> M >> D;
	int res = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= D; j++) {
			int d1 = j % 10;
			int d10 = j / 10;
			if (d1 >= 2 && d10 >= 2) {
				if (d1 * d10 == i) {
					res++;
				}
			}

		}
	}
	cout << res << endl;
}