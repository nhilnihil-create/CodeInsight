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

int main() {
	int n;
	cin >> n;
	vector<int>a(n-1), b(n-1);
	vector<vector<int>>c(n);
	rep(i, n - 1) {
		int p, q;
		cin >> p >> q;
		p--, q--;
		a[i] = p; b[i] = q;
		c[p].push_back(q);
		c[q].push_back(p);
	}
	int m(0);
	rep(i, n) {
		int k = c[i].size();
		m = max(m, k);
	}
	cout << m << endl;
	queue<P>q;
	map<P, int>mp;
	q.push(P(0, -1));
	vector<bool>f(n, false);
	f[0] = true;
	while (!q.empty()) {
		auto p = q.front(); q.pop();
		int t = p.first; int co = p.second;
		int color = 1;
		if (co == color) {
			color++;
		}
		for (auto n : c[t]) {
			if (!f[n]) {
				f[n] = true;
			}
			else {
				continue;
			}
			P pp = make_pair(t, n);
			mp[pp] = color;
			q.push(P(n, color));
			color++;
			if (t >= n)swap(t, n);
			
			//cout << pp.first << " " << pp.second << endl;
			
			if (co == color) {
				color++;
			}
		}
	}
	rep(i, n - 1) {
		int aa = a[i]; int bb = b[i];
		if (aa >= bb)swap(aa, bb);
		P pp = make_pair(aa, bb);
		//cout << pp.first << " " << pp.second << endl;
		cout << mp[pp] << endl;
	}
	return 0;
}