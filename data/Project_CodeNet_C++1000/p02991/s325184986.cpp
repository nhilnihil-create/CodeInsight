#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dp[100005][3];

const int INF = 1e9;

struct State{
	int cur, cnt, dist;
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> G(n);
	rep(i,m){
		int u, v;
		cin >> u >> v;
		--u; --v;
		G[u].push_back(v);
	}
	int s, t;
	cin >> s >> t;
	--s; --t;
	rep(i,100005)rep(j,3) dp[i][j] = INF;
	dp[s][0] = 0;
	State v;
	v.cur = s;
	v.cnt = 0;
	v.dist = 0;
	queue<State> que;
	que.push(v);
	while(!que.empty()){
		v = que.front();
		que.pop();
		int nx_cnt = (v.cnt + 1) % 3;
		for(auto to : G[v.cur]){
			if(dp[to][nx_cnt] <= v.dist + 1) continue;
			dp[to][nx_cnt] = v.dist + 1;
			State nv;
			nv.cur = to;
			nv.cnt = nx_cnt;
			nv.dist = v.dist + 1;
			que.push(nv);
		}
	}
	int ans;
	if(dp[t][0] == INF || dp[t][0]%3 != 0) ans = -1;
	else ans = dp[t][0] / 3;
	cout << ans << endl;
    return 0;
}
