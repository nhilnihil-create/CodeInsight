#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 10;
int fight[MAXN][MAXN], pv[MAXN];

int main(){
	ios::sync_with_stdio(0);
	cout << setprecision(10) << fixed;
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i){
		fight[i][0] = 1;
		for (int j = 1; j <= n - 1; ++j){
			cin >> fight[i][j];
		}
	}
	int day = 1;
	while (1){
		bool flag = false;
		for (int i = 1; i <= n; ++i){
			int done = fight[i][0];
			if (done == n || pv[i] == day){
				continue;
			}
			int oppo = fight[i][done];
			int od = fight[oppo][0];
			if (pv[oppo] != day && od < n && fight[oppo][od] == i){
				fight[i][0]++, fight[oppo][0]++;
				pv[i] = pv[oppo] = day;
				flag = true;
			}
		}
		if (!flag){
			break;
		}
		day++;
	}
	for (int i = 1; i <= n; ++i){
		if (fight[i][0] != n){
			cout << -1;
			return 0;
		}
	}
	cout << day - 1;
	return 0;
}

