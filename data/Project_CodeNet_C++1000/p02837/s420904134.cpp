#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N;
	cin >> N;

	vector <int> A(N);
	vector< vector<int> > x(N, vector <int> ());
	vector< vector<int> > y(N, vector <int> ());
	for (int ii = 0; ii < N; ++ii){
		cin >> A[ii];
		for (int jj = 0; jj < A[ii]; ++jj){
			int xx, yy;
			cin >> xx >> yy;
			xx--;
			x[ii].push_back(xx);
			y[ii].push_back(yy);
		}
	}

	int ans = 0;
	for (int n = 0; n < (1<<N); ++n){
		bitset< 1<<15 > bs(n);
		bool ok = true;
		for (int ii = 0; ii < N; ++ii){
			if (bs[ii] == 0) continue;
			for (int jj = 0; jj < A[ii]; ++jj){
				int hito = x[ii][jj];
				int honest = y[ii][jj];
				if (bs[hito]){
					if (honest == 0){
						ok = false;
						break;
					}
				} else {
					if (honest == 1){
						ok = false;
						break;
					}
				}
			}
		}
		if (ok){
			int score = bs.count();
			ans = max(ans, score);
		}
	}

	cout << ans << "\n";

	return 0;
}
