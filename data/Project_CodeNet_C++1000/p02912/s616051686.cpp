#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	int n, m;
	cin >> n >> m;
	priority_queue<int> q;
	rep(i,n) {
		int a;
		cin >> a;
		q.push(a);
	}
	for (int i = 0; i < m; i++) {
		int a = q.top(); q.pop();
		a /= 2;
		q.push(a);
	}
	ll ans = 0;
	while (!q.empty()) {
		int a = q.top(); q.pop();
		ans += a;
	}
	cout << ans << endl;
}