#include <bits/stdc++.h>
using namespace std;

using db = double;
using ll = long long;
using vi = vector <int>;
#define op operator
#define pb push_back

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

const int N = 33;

bool s[N][N], v[N][N];

int main() {
	cout << fixed << setprecision(9);
	ios :: sync_with_stdio(0);

	for(int n; cin >> n && n; ) {
		memset(s, 0, sizeof s);
		for(int i = 0; i < n; i ++) {
			int x, y; cin >> x >> y;
			s[x][y] = 1;
		}
		int m; cin >> m;
		memset(v, 0, sizeof v);
		int x = 10, y = 10;
		while(m --) {
			char c; int t; cin >> c >> t;
			int d = (c == 'N') ? 0 : (c == 'E') ? 1 : (c == 'S') ? 2 : 3;
			while(t --) {
				x += dx[d]; y += dy[d];
				v[x][y] = 1;
			}
		}

		bool f = 1;
		for(int i = 0; i <= 20; i ++)
			for(int j = 0; j <= 20; j ++)
				if(s[i][j] && !v[i][j]) f = 0;

		cout << (f ? "Yes" : "No") << '\n';
	}

	return 0;
}