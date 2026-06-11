#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define rep(i,n) for(int i=0;i<n;i++)
#define each(i,n) for(auto &i:n)

int n, m, a, b;
vi e[10000];

vi tsort(int v, vi *e) {
	stack<int> st;
	int ny[v] = {0};
	rep(i,v) rep(j,e[i].size()) ny[e[i][j]]++;
	rep(i,v) {
		if (ny[i]) continue;
		st.push(i);
	}
	vi res;
	while (!st.empty()) {
		int ne = st.top(); st.pop();
		res.push_back(ne);
		rep(i,e[ne].size()) if (--ny[e[ne][i]]==0) st.push(e[ne][i]);
	}
	return res;
}

int main() {
	cin >> n >> m;
	rep(i,m) {
		cin >> a >> b;
		e[a].push_back(b);
	}
	vi r = tsort(n,e);
	rep(i,n) cout << r[i] << endl;
}
