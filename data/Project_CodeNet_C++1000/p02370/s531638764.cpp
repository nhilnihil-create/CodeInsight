//トポソの唯一性
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
 
int main(){
 
    int n, m; cin >> n >> m;
    vector<vector<int> > adj(n);
    vector<int> d(n, 0);                           //入次数
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;                   //a->bへ有向辺
        d[b]++;
        adj[a].push_back(b);
    }
 
    queue<int> q;
 
    //入次数が0の頂点queueに入れる
    for(int i = 0; i < n; i++){
        if(d[i] == 0) q.push(i);                    
    }
 
    vector<int> ans;
 
    while(!q.empty()){
 
        int v = q.front();
        q.pop();
        ans.push_back(v);
 
        //vから伸びている有向辺をなめる
        for(int i = 0; i < (int)adj[v].size(); i++){
            d[adj[v][i]]--;
            //辺を取り除いた後に入次数が0になったら
            if(d[adj[v][i]] == 0) q.push(adj[v][i]);
        }
 
    }
 
    for(int i = 0; i < (int)ans.size(); i++) cout << ans[i] << endl;
    return 0;
}
