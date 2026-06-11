#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int n;
vector<vector<int>> a;

void dfs(vector<int> v, int lev){
	int m = v.size();
	if(m == 1) return;

	vector<int> s, t;
	rep(i, m){
		if(i % 2 == 0) s.push_back(v[i]);
		if(i % 2 == 1) t.push_back(v[i]);
	}

	for(int x : s) for(int y : t) {
		a[x][y] = lev;
		a[y][x] = lev;
	}
	
	dfs(s, lev + 1);
	dfs(t, lev + 1);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	a.resize(n, vector<int>(n));

	vector<int> v(n);
	rep(i, n) v[i] = i;

	dfs(v, 1);
	
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			cout << a[i][j] << (j == n - 1 ? "\n" : " ");
		}
	}
}
