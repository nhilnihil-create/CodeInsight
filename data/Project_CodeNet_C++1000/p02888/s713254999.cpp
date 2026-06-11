#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int n;
	cin >> n;
	vector<int>stick(n);
	vector<int>sticks;
	rep(i, n)cin >> stick[i];
	sort(all(stick));
	sticks = stick;
	sort(rall(stick));
	int c, ans = 0;
	rep(i, n-2) {
		for (int j = i + 1; j < n - 1; j++) {
			c = stick[i] - stick[j] + 1;
			auto itr = lower_bound(sticks.begin(), sticks.end() - (j+1), c);
			if (itr == sticks.end() -(j+1))continue;
			ans += (sticks.end() - itr) - (j+1);
		}
	}
	cout << ans << endl;
	return 0;
}

