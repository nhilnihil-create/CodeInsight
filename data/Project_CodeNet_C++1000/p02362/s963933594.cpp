#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair <int, int> pii;
typedef pair <pii, int> ppiii;

const int INF = 0x3f3f3f3f;
int n, m, r, t1, t2, t3, d[100005];
vector <ppiii> e;

int main() {
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) d[i] = INF;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2 >> t3;
		e.pb(mp(mp(t1, t2), t3));
	}
	d[r] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (ppiii j : e) {
			int &u = j.fi.fi, &v = j.fi.se, &w = j.se;
			if (d[u] != INF && d[u] + w < d[v]) {
				d[v] = d[u] + w;
			}
		}
	}
	for (ppiii i : e) {
		int &u = i.fi.fi, &v = i.fi.se, &w = i.se;
		if (d[u] != INF && d[u] + w < d[v]) {
			cout << "NEGATIVE CYCLE" << endl;
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (d[i] == INF) cout << "INF" << endl;
		else cout << d[i] << endl;
	}
}

