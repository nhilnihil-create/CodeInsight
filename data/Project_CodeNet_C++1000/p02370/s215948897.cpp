#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> color(10005,0),indeg(10005,0);
vector<vector<int>> G(10005,vector<int>(0));
list<int> ans;

void bfs(int s){
    queue<int> Q;
    Q.push(s);
    color[s]=1;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        ans.push_back(u);
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            indeg[v]--;
            if(indeg[v]==0&&color[v]==0){
                color[v]=1;
                Q.push(v);
            }
        }
    }
}

void tsort(){
    for(int i=0;i<n;i++){
        for(int j=0;j<G[i].size();j++){
            indeg[G[i][j]]++;
        }
    }

    for(int i=0;i<n;i++){
        if(indeg[i]==0&&color[i]==0) bfs(i);
    }
}

int main(){
    int a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        G[a].push_back(b);
    }
    
    tsort();

    for(auto i=ans.begin();i!=ans.end();i++){
        cout<<*i<<endl;
    }
}
