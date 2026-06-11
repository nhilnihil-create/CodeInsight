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
	int N;
	cin >> N;

	vector<vector<int> > res(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int t = (i ^ j);
			res[i][j] = 1;
			while (t % 2 == 0) {
				t /= 2;
				res[i][j]++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			cout << res[i][j];
			if (j < N - 1) cout << " ";
		}
		cout << endl;
	}

}