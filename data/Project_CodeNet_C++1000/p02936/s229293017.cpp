#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

vector<vector<int>> E;
vector<int> c;
vector<int> ans;
vector<bool> visited;

void dfs(int i, int value){
	visited[i] = true;
	ans[i] = value+c[i];
	
	for(int child: E[i]){
		if(visited[child]) continue;
		dfs(child, ans[i]);
	}
}

int main(){
	int n,q;
	cin >> n >> q;
	E.resize(n);
	int a,b;
	REP(i,n-1){
		cin >> a >> b;
		E[a-1].push_back(b-1);
		E[b-1].push_back(a-1);
	}
	vector<int> p(n,0);
	REP(i,q){
		cin >> a >> b;
		p[a-1] += b;
	}
	c = p;

	ans.resize(n);
	visited.resize(n);
	fill(visited.begin(),visited.end(),false);
	dfs(0,0);
	
	REP(i,n){
		if(i!=0) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	
	return 0;
}