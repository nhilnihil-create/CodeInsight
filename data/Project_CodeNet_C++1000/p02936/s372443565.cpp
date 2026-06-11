#include "bits/stdc++.h"
#include <set>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(i) (i).begin(), (i).end()
#define rall(i) (i).begin(), (i).end(), greater<int>()
//#define int long long
#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second
#define mod 1000000007
#define INF 10e10
template <typename T>

void print(T x)
{
	std::cout << x << " ";
}

template <typename T>

void println(T x)
{
	std::cout << x << "\n";
}

vector<int>ans(200001,0);
vector<int>visited(200001,0);
vector<vector<int>>G(200001,vector<int>());
queue<int>que;
void bfs(){
	while (!que.empty()) {
		int v = que.front();
		que.pop();
		for (int nv : G[v]) {
			if(visited[nv]==1)continue;
			ans[nv]+=ans[v];
			que.push(nv);
			visited[nv]=1;
		}
	}

}

signed main(void) {
	int n,q;
	cin >> n >> q;
	ans.resize(n);
	visited.resize(n);
	rep(i,n-1){
		int a,b;
		cin >> a>>b;
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	rep(i,q){
		int p,x;
		cin >> p>>x;
		p--;
		ans[p]+=x;
	}
	visited[0]=1;
	que.push(0);
	bfs();
	for(auto a:ans){
		print(a);
	}
}