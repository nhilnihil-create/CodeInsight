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
	int n, m;
	cin >> n >> m;
	priority_queue<int> q;
	rep(i,n) {
		int a;
		cin >> a;
		q.push(a);
	}
	while (m > 0) {
		int a = q.top();
		q.pop();
		a /= 2;
		q.push(a);
		m--;
	}
	ll ans = 0;
	while (!q.empty()) ans += q.top(), q.pop();
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}