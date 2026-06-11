#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;
using Graph = vector<vector<int>>;


int main(){
    int n,x,y;
    cin >> n >> x >> y;
    x--; y--;
    Graph G(n);
    vector<int> D(n+1);
    for(int i=0; i<n-1; i++){
        G[i].push_back(i+1);
        G[i+1].push_back(i);
    }
    G[x].push_back(y);
    G[y].push_back(x);
    for(int i=0; i<n; i++){
        vector<int> dist(n,-1);
        queue<int> que;
        dist[i] = 0;
        que.push(i);
        
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int nv : G[v]){
                if(dist[nv] != -1) continue;
                dist[nv] = dist[v]+1;
                que.push(nv);
            }
        }
        for(int j=0; j<n; j++){
            D[dist[j]]++;
        }
    }
    

    for(int i=1; i<=n-1; i++){
        cout << D[i]/2 << endl;
    }       
    return 0;
}