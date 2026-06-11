#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> v;
	int flag = 0;
	int cnt = 0;
	rep(i,n) {
		if ((flag == 0 && s[i] == 'L') || (flag == 1 && s[i] == 'R')) {
			cnt++;
		} else {
			v.push_back(cnt);
			cnt = 1;
			flag = 1 - flag;
		}
	}
	if (cnt) v.push_back(cnt);
	int ans = 0;
	for (int t: v) {
		if (t > 1) ans += t - 1;
	}
	cout << min(ans + 2 * k, n - 1) << endl;
}

int main() {
	solve();
	return 0;
}