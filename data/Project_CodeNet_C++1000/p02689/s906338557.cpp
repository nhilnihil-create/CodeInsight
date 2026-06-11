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
	vector<int> h(n);
	rep(i,n) cin >> h[i];
	vector<vector<int>> to(n);
	rep(i,m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		to[a].push_back(b);
		to[b].push_back(a);
	}

	int ans = 0;
	rep(i,n) {
		bool b = true;
		for (int j: to[i]) {
			if (h[i] <= h[j]) b = false;
		}
		if (b) ans++;
	}
	cout << ans << endl;
}