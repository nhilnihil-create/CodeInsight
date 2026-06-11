#include<bits/stdc++.h>
#define ll long long
#define P pair<ll, ll>
using namespace std;

const int inf = 1e9;

vector<vector<int>> G (2005);
vector<vector<int>> dis (2005, vector<int>(2005, inf));

void dfs(int p, int num, int d){
    for(auto to: G[num]){
        if(dis[p][to] >= d && dis[to][p] >= d){
            dis[p][to] = d;
            dis[to][p] = d;
            dfs(p, to, d+1);
        }
    }
}

int main(){
    int n, x, y;
    cin >> n >> x >> y;

    for(int i=0;i<n-1;i++){
        G[i].push_back(i+1);
        G[i+1].push_back(i);
    }
    G[x-1].push_back(y-1);
    G[y-1].push_back(x-1);

    for(int i=0;i<n;i++) dis[i][i] = 0;
    for(int i=0;i<n-1;i++) dfs(i, i, 1);

    vector<int> ans(n, 0);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans[dis[i][j]]++;
        }
    }

    for(int i=1;i<n;i++) cout << ans[i] << endl;
}