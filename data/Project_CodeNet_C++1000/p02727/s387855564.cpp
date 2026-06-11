#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
const int N = 1e5 + 10;
int p;

ll sum[N][3];
int main() {
	int x,y,a,b,c;
	cin >> x >> y >> a >> b >> c;
	priority_queue<P> pq;
	rep(i,a) {
		cin >> p;
		pq.push({p,0});
	}
	rep(i,b) {
		cin >> p;
		pq.push({p,1});
	}
	rep(i,c) {
		cin >> p;
		pq.push({p,2});
	}
	int red = 0, green = 0, cless = 0;
	rep(i,x+y) {
		P pp = pq.top(); pq.pop();
		p = pp.first;
		int idx = pp.second;
		if (idx == 0) {
			sum[red+1][0] = sum[red][0] + p; 
			red++;
		}
		else if (idx == 1) {
			sum[green+1][1] = sum[green][1] + p;
			green++;
		} else {
			sum[cless+1][2] = sum[cless][2] + p;
			cless++;
		}
	}
	ll ans;
	if (red <= x && green <= y) {
		ans = sum[red][0] + sum[green][1] + sum[cless][2];
	} else if (red > x) {
		ans = sum[x][0] + sum[green][1] + sum[cless][2];
		while (green + cless < y)
		{
			P pp = pq.top(); pq.pop();
			if (pp.second == 0) continue;
			ans += pp.first;
			green++;
		}
	} else {
		ans = sum[red][0] + sum[y][1] + sum[cless][2];
		while (red + cless < x)
		{
			P pp = pq.top(); pq.pop();
			if (pp.second == 1) continue;
			ans += pp.first;
			red++;
		}
	}
	cout << ans << endl;
	return 0;
}