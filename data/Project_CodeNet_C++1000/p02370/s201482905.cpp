#include <cstdio>
#include <vector>
#include <forward_list>
#include <queue>

using namespace std;

int cnt = 0;
int cntp = 0;

queue<int> source;
vector<int> pre;
vector<int> in;

class Edge{
public:
  int v;
  int w;
  Edge(int vi,int wi):v(vi),w(wi){;}
};

class Graph{
public:
    int V;
    int E;
    vector<forward_list<int>> adj_list;
    Graph(int v,int e):V(v),E(e){
        adj_list.resize(V);
        pre.resize(V);
        in.resize(V);
        for(int i = 0; i < V;i++) {pre[i] = -1;in[i] = 0;}
    }
    void addEdge(int v,int w){
        adj_list[v].push_front(w);
    }
};

int main(){
    int V,E,v,w;
    scanf("%d %d",&V,&E);
    Graph G(V,E);
    for(int i = 0; i < E;i++){
        scanf("%d %d",&v,&w);
        G.addEdge(v,w);
        in[w]++;
    }

    for(int i = 0; i < V;i++){
        if(!in[i]) source.push(i);
    }
    while(!source.empty()){
        int j = source.front();
        pre[j] = 0;
        printf("%d\n",j);
        source.pop();
        for(auto a = G.adj_list[j].begin();a!=G.adj_list[j].end();++a){
            int v = *a;
            if(pre[v] == -1){
               if(--in[v] == 0)
                    source.push(v);
            }
        }
    }
    return 0;
}

