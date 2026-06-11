#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define EFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i, n) FOR(i,0,n)
#define INF 1e12
const int MOD = 1000000007;
typedef pair<ll,ll> P;

// BFS O(N^2)の解法
int main(void){
    int N,X,Y;
    cin >> N >> X >> Y;
    X--; Y--;   //0-indexed
    Graph dist(N,vector<int>(N,-1));
    FOR(i,0,N){
        queue<int> que;
        que.push(i);
        dist[i][i] = 0;
        while(!que.empty()){
            int v = que.front();
            vector<int> vis;
            que.pop();
            if(v > 0)   vis.push_back(v-1);
            if(v < N-1) vis.push_back(v+1);
            if(v == X)  vis.push_back(Y);
            if(v == Y)  vis.push_back(X);
            for(auto vs:vis){
                if(dist[i][vs] != -1) continue;
                dist[i][vs] = dist[i][v] + 1;
                que.push(vs);
            }
        }
    }
    vector<int> ans(N+10, 0);
    REP(i,N){
        FOR(j,i+1,N){
            ans[dist[i][j]]++;
        }
    }
    FOR(i,1,N) cout << ans[i] << endl;
    return 0;
}