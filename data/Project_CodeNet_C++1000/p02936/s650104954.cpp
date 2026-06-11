#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
struct node{
    vector<int> to;
    int counter;
    int add;
    node(){
        counter=0;
        add=0;
    }
};
void dfs(int v, int p, vector<node> &nodes, int sum_add){
    nodes[v].counter=sum_add;
    for (int i = 0; i < nodes[v].to.size(); i++){
        int v_to=nodes[v].to[i];
        if(v_to==p)continue;
        dfs(v_to, v, nodes, sum_add+nodes[v_to].add);
    }
}
int main() {
    int N;
    cin>>N;
    int Q;
    cin>>Q;
    vector<node> nodes(N);
    for (int i = 0; i < N-1; i++){
        int u,v;
        cin>>u>>v; u--; v--;
        nodes[u].to.push_back(v);
        nodes[v].to.push_back(u);
    }
    for (int i = 0; i < Q; i++){
        int p,x; cin>>p>>x; p--;
        nodes[p].add+=x;
    }
    dfs(0,-1,nodes,nodes[0].add);
    for (int i = 0; i < N; i++){
        cout<<nodes[i].counter<<endl;
    }
}