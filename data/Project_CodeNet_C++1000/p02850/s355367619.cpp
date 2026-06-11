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

vector<int>res;
vector<vector<int>>c;
map<P, int>mp;
vector<bool>f;

void dfs(int v ,int p,int pc){
	int color = 1;
	
	if (pc == color)color++;
	//cout << color << endl;
	//cout << v << endl;
	for (auto e : c[v]) {
		if (!f[e]) {
			f[e] = true;
		}
		else {
			continue;
		}
		if (v >= e)swap(v, e);
		P p = make_pair(v, e); 
		//cout << color << endl;
		mp[p] = color;
		dfs(e, v, color);
		color++;
		if (color == pc)color++;
	}
}

int main() {
	int n;
	cin >> n;
	vector<int>a(n-1), b(n-1);
	c.resize(n);
	res.resize(n - 1, -1);
	f.resize(n, false);
	rep(i, n - 1) {
		int p, q;
		cin >> p >> q;
		p--, q--;
		a[i] = p; b[i] = q;
		c[p].push_back(q);
		c[q].push_back(p);
	}
	int m(0);
	f[0] = true;
	rep(i, n) {
		int k = c[i].size();
		m = max(m, k);
	}
	cout << m << endl;
	dfs(0, -1, -1);
	rep(i, n - 1) {
		int aa = a[i]; 
		int bb = b[i];
		if (aa >= bb)swap(aa, bb);
		P p = make_pair(aa,bb);
		cout << mp[p] << endl;
	}
	
	return 0;
}