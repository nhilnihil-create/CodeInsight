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
	int n, k;
	cin >> n >> k;
	vector<int>arr(n);
	rep(i, n)cin >> arr[i];
	int l = 0, r = 1e9;
	while (r - l> 1) {
		int m = (l + r) / 2;
		ll cnt = 0;
		rep(i, n)cnt += (arr[i] - 1) / m;
		if (cnt <= k)r = m;else l = m;
	}
	cout << r << endl;
	return 0;
}

