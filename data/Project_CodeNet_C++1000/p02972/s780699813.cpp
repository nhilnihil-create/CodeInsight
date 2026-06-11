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
	int n;
	cin >> n;
	vector<int> v(n);
	rep(i,n) cin >> v[i];
	vector<int> cnt(n);
	for (int i = n - 1; i >= 0; i--) {
		int temp = 0;
		for (int j = i; j < n; j += i + 1) {
			if (j == i) continue;
			if (cnt[j]) temp++;
		}
		if (temp % 2 != v[i]) cnt[i]++;
	}
	vector<int> ans;
	rep(i,n) if (cnt[i]) ans.push_back(i + 1);
	cout << ans.size() << endl;
	if (ans.size()) {
		rep(i,ans.size()) cout << ans[i] << " "; 
		cout << endl;
	}
}

int main() {
	solve();
	return 0;
}