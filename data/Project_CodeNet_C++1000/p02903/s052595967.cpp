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
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	vector<vector<int>> g(h, vector<int>(w,0));
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < a; j++) {
			g[i][j] = 1;
		}
	}
	for (int i = b; i < h; i++) {
		for (int j = a; j < w; j++) {
			g[i][j] = 1;
		}
	}
	rep(i,h) {
		rep(j,w) cout << g[i][j];
		cout << endl;
	}
}