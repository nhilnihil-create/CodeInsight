#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;



int main(void) {
	int N; cin >> N;
	vector<int> L(N); rep(i, N)cin >> L[i];
	sort(L.begin(), L.end());

	int ans = 0;
	rep(i, N)rep(j, i) {
		int k = lower_bound(L.begin(), L.end(), L[i] + L[j]) - L.begin();
		int l = i + 1;
		ans += max(0, k - l);
	}

	cout << ans << endl;

	return 0;
}