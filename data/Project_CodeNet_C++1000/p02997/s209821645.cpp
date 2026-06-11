#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int n, k;
	cin >> n >> k;
	int m = n-1;
	int mx = (n-1) * (n-2) / 2;
	if(k > mx) {
		cout << -1 << endl;
		return 0;
	}
	int now = mx;
	vector<pair<int, int>> ans;
	rep(i, n-1) {
		ans.push_back(make_pair(1, i+2));
	}
	rep(i, n-1) {
		if (now == k) break;
		if(i == n-2)ans.push_back(make_pair(i+2, 2));
		else ans.push_back(make_pair(i+2, i+3));
		now--;
	}
	for(int i = 2; i <= n-2; i++) {
		for(int j = i+2; j <= n; j++) {
			if (now == k) break;
			if(i==2 && j==n) continue;
			ans.push_back(make_pair(i, j));
			now--;
		}
	}
	cout << ans.size() << endl;;
	for(auto t: ans) printf("%d %d\n", t.first, t.second);
	return 0;
}