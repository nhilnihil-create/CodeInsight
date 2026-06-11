#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
    int n,x,y;
    cin >> n >> x >> y;
    x--;y--;
    vector<int> ans(n);
    vector<vector<int>> G(n);
    G[0].push_back(1);
    G[n-1].push_back(n-2);
    G[x].push_back(y);
    G[y].push_back(x);
    for(int i = 1;i<n-1;i++){
        G[i].push_back(i-1);
        G[i].push_back(i+1);
    } 
    rep(i,n){
        queue<int> que;
        que.push(i);
        vector<int> dist(n,-1);
        dist[i] = 0;
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(auto j : G[v]){
                if(dist[j]==-1){
                    dist[j] = dist[v] + 1;
                    ans[dist[j]]++;
                    que.push(j);
                }
            }
        }
    }
    rep(i,n-1){
        cout << ans[i+1]/2 << endl;
    }
}