#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<int, int> p;
int main(){
    int n, x, y; cin >> n >> x >> y; x--; y--;
    vector<vector<int>> g(n);
    for(int i=0; i+1<n; ++i){
        g[i].push_back(i+1);
        g[i+1].push_back(i);
    }
    g[x].push_back(y); 
    g[y].push_back(x);
    
    queue<int> que;
    vector<int> res(n, 0);
    for(int i=0; i<n; ++i){
        vector<int> dist(n, -1); dist[i] = 0;
        que.push(i); 
        while(!que.empty()){
            int v = que.front(); que.pop();// cout << "v:" << v << ",";
            
            for(auto nv : g[v]){
              	if(dist[nv]!=-1){continue;}
                que.push(nv);
                dist[nv] = dist[v] + 1;
            }
        } /*for(int j=0; j<n; ++j){
            cout << dist[j] << ",";
        } cout << endl;*/
        for(int j=0; j<n; ++j){
            int d = dist[j];
            res[d]++;
        }
    }
    for(int i=1; i<n; ++i){cout << res[i]/2 << endl;}
    return 0;
}