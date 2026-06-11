#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const long long INF = 1LL << 61;
const int MOD = 2019;

int main() {
	int n; cin >> n;
	vector<int> p(n);
	rep(i, n)cin >> p[i];
	int ans = 0;
	for (int i = 1; i < n - 1; ++i) {
		int max = *max_element(p.begin() + i - 1, p.begin() + i + 2);
		int min = *min_element(p.begin() + i - 1, p.begin() + i + 2);
		//cout << max << " " << min << endl;
		if (p[i] != max && p[i] != min)++ans;
	}
	cout << ans;
}