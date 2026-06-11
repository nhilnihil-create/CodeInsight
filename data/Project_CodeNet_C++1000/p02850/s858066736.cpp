#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
struct node{
    int a;
    vi to;
    vi edge_id;
};
int K;
void dfs(int v, int p, vector<node> &nodes, vi &color, int p_color){
    K=max(K,(int)nodes[v].to.size());
    int color_id=1;
    for (int i = 0; i < nodes[v].to.size(); i++){
        int v_to=nodes[v].to[i];
        if(v_to==p)continue;
        if(color_id==p_color)color_id++;
        color[nodes[v].edge_id[i]]=color_id;
        dfs(v_to, v, nodes, color, color_id);
        color_id++;
    }
}
int main() {
    int N;
    cin>>N;
    K=0;
    vector<node> nodes(N);
    vi color(N-1,0);
    for (int i = 0; i < N-1; i++){
        int u,v;
        cin>>u>>v;u--;v--;
        nodes[u].to.push_back(v);
        nodes[v].to.push_back(u);
        nodes[u].edge_id.push_back(i);
        nodes[v].edge_id.push_back(i);
    }
    dfs(0,-1,nodes,color,0);
    cout<<K<<endl;
    for(int x : color)cout<<x<<endl;
}