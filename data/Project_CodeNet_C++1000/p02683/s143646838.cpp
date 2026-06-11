#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>
const int INF = 1e9;
int main() {
	int n, m, t;
	cin >> n >> m >> t;
	vector<int>c(n);
	vector<vector<int>>a(n);
	rep(i, n) {
		cin >> c[i];
		rep(j, m) {
			int buf;
			cin >> buf;
			a[i].push_back(buf);
		}
	}
	int ans = INF;
	for (int i = 0; i <(1<<n); ++i) {
		vector<int>x(m);
		int cnt(0);
		int sum(0);
		
		rep(j, n) {
			
			if ((i >> j) & 1) {
				//cout << i << " " << j << endl;
				sum += c[j];
				rep(k, m)x[k] += a[j][k];
			}
		}
		rep(k, m) {
			if (x[k] >= t) {
				cnt++;
			}
		}
		if (cnt == m)ans = min(ans, sum);
	}
	if (ans == INF)cout << "-1";
	else cout << ans;
	return 0;
}