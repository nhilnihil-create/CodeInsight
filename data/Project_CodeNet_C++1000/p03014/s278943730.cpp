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
int cnr[2000][2000];
int cnl[2000][2000];

int main() {
	int h, w;
	cin >> h >> w;
	vector<string>a(h);
	rep(i, h) {
		cin >> a[i];
	}
	vector<queue<int>>q(h);
	bool ok(true);

	rep(i, h) {
		int cnt(0);
		rep(j, w) {
			//cout << i << " " << j << endl;
			if (a[i][j] == '#') {
				if (ok) {
					ok = false;
					q[i].push(cnt);
					cnt = 0;
				}
				
			}
			else {
				ok = true;
				cnt++;
			}
		}
		//cout << cnt << endl;
		q[i].push(cnt);
	}
	ok=true;
	int kk(0);
	rep(i, h)rep(j, w) {
		if (a[i][j] == '#') {
			if (ok) {
				ok = false;
				q[i].pop();
				continue;
			}
		}
		else {
			ok = true;
			cnr[i][j] = q[i].front();
			//cout << i << j << cnr[i][j] << endl;
			kk = max(kk, cnr[i][j]);
		}
	}
	//cout << kk;
	vector<queue<int>>qq(w);
	bool ok2(true);

	rep(i, w) {
		int cnt(0);
		rep(j, h) {
			if (a[j][i] == '#') {
				if (ok2) {
					ok2 = false;
					qq[i].push(cnt);
					cnt = 0;
				}
				
			}
			
			else {
				ok2 = true;
				cnt++;
			}
		}
		qq[i].push(cnt);
	}
	ok2 = true;
	rep(i, w)rep(j, h) {
		if (a[j][i] == '#') {
			if (ok2) {
				ok2 = false;
				qq[i].pop();
				continue;
			}
		}
		else {
			ok2 = true;
			cnl[j][i] = qq[i].front();
		}
	}
	int ans(0);
	rep(i, h)rep(j, w) {
		 ans = max(ans, cnr[i][j] + cnl[i][j]);
	}
	ans--;
	cout << ans;
	return 0;
}