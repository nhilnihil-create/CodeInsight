#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int N;
vector<pair<int,int>> g[1001][1001];
int deg[1001][1001] = {};
deque<pair<int,int>> res;
queue<pair<int,int>> ver;
bool tsort(){
	while(!ver.empty()){
		pair<int,int> v = ver.front(); ver.pop();
        res.push_front(v);
		for(pair<int,int> u:g[v.first][v.second]){
            int s = u.first;
            int t = u.second;
            deg[s][t]--;
			if(deg[s][t] == 0) ver.push({s, t});
		}
	}
	rep(i,1,N+1)rep(j,1,i)if(deg[i][j]) return false;
    return true;
}
int dfs(int v, int u){
    int res = 0;
    if(g[v][u].size() == 0) return 0;
    for(pair<int,int> p:g[v][u]){
        int s = p.first;
        int t = p.second;
        res = max(res, dfs(s, t));
    }return res + 1;
}
int main(){
	cin>>N;
	rep(i,1,N+1){
		int a,b; cin>>a;
		rep(j,2,N){
			cin>>b;
			g[max(i, a)][min(i, a)].push_back({max(i, b), min(i, b)});
            deg[max(i, b)][min(i, b)]++;
            a = b;
		}
	}
    rep(i,1,N+1)rep(j,1,i){
        if(deg[i][j] == 0) ver.push({i, j});
    }
    int dp[N+1][N+1];
    if(ver.size() && tsort()){
        rep(i,0,N * (N - 1) / 2){
            pair<int,int> v = res[i];
            if(g[v.first][v.second].size() == 0){ dp[v.first][v.second] = 0; continue; }
            int temp = 0;
            for(pair<int,int> p:g[v.first][v.second]) temp = max(temp, dp[p.first][p.second]);
            dp[v.first][v.second] = temp + 1;
        }
        int ans = 0;
        rep(i,1,N+1)rep(j,1,i) ans = max(ans, dp[i][j]);
        cout<<ans + 1<<endl;
        return 0;
    }cout<<-1<<endl;
}