#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;
int main(){
    int N,M;
    cin>>N>>M;
    vector<vector<int>> tree(3*N,vector<int>(0));
    for(int i=0;i<M;i++){
        int u,v;//[1,N]
        cin>>u>>v;
        //cout<<" "<<u<<" "<<v<<endl;
        tree.at(u-1).push_back(N+v-1);
        tree.at(N+u-1).push_back(2*N+v-1);
        tree.at(2*N+u-1).push_back(v-1);
    }
    int S,G;
    cin>>S>>G;
    vector<int> dist(3*N,-1);
    queue<int> que;
    dist[S-1]=0;
    que.push(S-1);
    while(!que.empty()){
        int v=que.front();
        que.pop();
        for(int i=0;i<(int)tree.at(v).size();i++){
            int nv=tree.at(v).at(i);
            if(dist[nv]!=-1 && dist[nv]<=dist[v]+1){
                continue;
            }
            dist[nv]=dist[v]+1;
            que.push(nv);
        }
    }
    if(dist[G-1]==-1){
        cout<<dist[G-1]<<endl;
    }
    else{
        cout<<dist[G-1]/3<<endl;
    }
}