#include<cstdio>
#include<map>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int,int> P;
typedef pair<int,P> edge; // cost, source, target


typedef struct UF {
    int par[10005];
    void init(int n) {
        for(int i=0; i<n; i++)
            par[i] = i;
    }
    int root(int x) {
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if(x==y) return true;

        par[x] = y;
        return false;
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
} UF;


int v,e;
UF uf;
priority_queue<edge, vector<edge>, greater<edge> > edges;

int main(void) {
    scanf("%d%d",&v,&e);
    for(int i=0; i<e; i++) {
        int s,t,d;
        scanf("%d%d%d",&s,&t,&d);
        edges.push(edge(d,P(s,t)));
    }
    int res = 0;
    uf.init(v);
    while(!edges.empty()) {
        edge e = edges.top(); edges.pop();
        int cost = e.first;
        int src = e.second.first, dst = e.second.second;
        if(uf.same(src,dst)) continue;
        res += cost;
        uf.unite(src,dst);
    }

    printf("%d\n", res);
    return 0;
}