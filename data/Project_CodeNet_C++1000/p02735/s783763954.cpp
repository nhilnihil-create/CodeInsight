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
	int h, w;
	cin >> h >> w;
	vector<string> v(h);
	rep(i,h) cin >> v[i];
	vector<vector<int>> cnt(h, vector<int>(w, INF));
	cnt[0][0] = (v[0][0] == '#');
	rep(i,h) {
		rep(j,w) {
			if (i == 0 && j == 0) continue;
			int t = INF;
			int u = INF;
			if (j != 0) {
				t = cnt[i][j-1];
				if (v[i][j-1] == '.' && v[i][j] == '#') t++;
			}
			if (i != 0) {
				u = cnt[i-1][j];
				if (v[i-1][j] == '.' && v[i][j] == '#') u++;
			}
			cnt[i][j] = min(t, u);
		}
	}

	cout << cnt[h-1][w-1] << endl;
}