#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

long long N;
vector<long long> tree[100005];
long long a[100005];
long long b[100005];
map<pair<long long, long long>, long long> ans;
set<long long> memo;
long long col[100005];

long long dfs(long long pa, long long pacolor, long long cur) {
	long long col = 0;
	for(auto next: tree[cur]) {
		if(next != pa) {
			if(col == pacolor) col++;
			ans[make_pair(min(cur, next), max(cur, next))] = col;
			memo.insert(col);
			dfs(cur, col, next);
			col++;
		}
	}
	return 0;
}

int main(){
	cin >> N;
	rep(i, N - 1) {
		cin >> a[i] >> b[i];
		a[i]--;b[i]--;
		tree[a[i]].push_back(b[i]);
		tree[b[i]].push_back(a[i]);
	}

	dfs(-1, -1, 0);

	cout << memo.size() << endl;
	rep(i, N - 1) {
		cout << ans[make_pair(min(a[i], b[i]), max(a[i], b[i]))] + 1 << endl;
	}

}