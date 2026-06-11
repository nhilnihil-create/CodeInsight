#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
vector<vector<int>> e;
vector<set<int>> cols;
map<P,int> col;
void rec(int now,int p){
	for(int next:e[now]){
		if(next != p){
			int next_cols = *cols[now].begin();
			cols[next].erase(next_cols);
			cols[now].erase(next_cols);
			col[P(next,now)] = next_cols;
			col[P(now,next)] = next_cols;
			rec(next,now);
		}
	}
}
int main(){
	int n;
	cin >> n;
	e.resize(n);
	cols.resize(n);
	vector<P> edges;
	for(int i = 0;i < n-1;i++){
		int a,b;
		cin >> a >> b;
		a--,b--;
		e[a].push_back(b);
		e[b].push_back(a);
		cols[a].insert(e[a].size());
		cols[b].insert(e[b].size());
		edges.push_back(P(a,b));
	}

	rec(0,-1);

	int k = 0;
	vector<int> ans;
	for(int i = 0;i < n-1;i++){
		ans.push_back(col[edges[i]]);
		k = max(k,col[edges[i]]);
	}

	cout << k << endl;
	for(int a:ans)cout << a << endl;
}
