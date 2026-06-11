#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i< (n);i++)
using namespace std;
typedef long long ll;

struct BFS{
    vector<int> color;
    vector<vector<int>> adj;
    int n_,m_;
    BFS(int n,int m):color(n,-1),adj(n){
        n_ = n;
        m_ = m;
    }
    void init(){
        rep(i,m_){
            int a,b;cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    void visit(int u,int clr){
        queue<int> Q;
        Q.push(u);
        color[u] = clr;
        while(!Q.empty()){
            int v = Q.front();Q.pop();
            color[v] = clr;
            for(int h:adj[v]){
                if(color[h] == -1){
                    Q.push(h);
                }
            }
        }
    }
    void go(){
        int clr_ = 0;
        rep(i,n_){
            if(color[i] == -1){
                visit(i,clr_);
                clr_++;
            }
        }
    }
    void solve(){
        init();
        go();
        int q;cin>>q;
        rep(i,q){
            int a,b;cin>>a>>b;
            if(color[a] == color[b]){
                cout<<"yes"<<endl;
            }else{
                cout<<"no"<<endl;
            }
        }
    }
};

int main(){
    int n,m;cin>>n>>m;
    BFS bfs(n,m);
    bfs.solve();
    return 0;
}
