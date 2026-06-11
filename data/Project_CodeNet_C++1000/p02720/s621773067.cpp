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
	int k;
	cin >> k;
	queue<ll> q;
	for (int i = 1; i <= 9; i++) q.push(i);
	int cnt = 0;
	while (true) {
		ll cur = q.front(); q.pop();
		cnt++;
		if (cnt == k) {
			cout << cur << endl;
			return;
		} else {
			int x = cur % 10;
			for (int i = -1; i <= 1; i++) {
				if (0 <= x + i && x + i <= 9) q.push(cur * 10 + x + i);
			}
		}
	}
}

int main() {
	solve();
	return 0;
}