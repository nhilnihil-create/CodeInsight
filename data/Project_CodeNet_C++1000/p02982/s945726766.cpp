#include "bits/stdc++.h"
using namespace std;

int main() {
	int N,D;
	cin >> N >>D; 
	vector<vector<int>> X(N, vector<int>(D));
	for (int n = 0;n<N;++n) {
		for (int d = 0;d<D;++d) {
			cin >> X[n][d];
		}
	}
	int ans = 0;
	for (int i = 0;i<N;++i) {
		for (int j = i + 1;j<N;++j) {
			int d = 0;
			for (int k = 0;k<D;++k) {
				d += (X[i][k]-X[j][k])*(X[i][k] - X[j][k]);
			}
			int dsub = (int)sqrt(d);
			dsub *= dsub;
			if (d == dsub) {
				++ans;
			}
		}
	}
	cout << ans << endl;
	return 0;
}