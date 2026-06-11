#include <cstdio>
struct UnionFind {
    int *par;
    int *rank;
    UnionFind(int n) {
        par=new int[n];
        rank=new int[n];
        for(int i=0;i<n;i++) {
            par[i]=i;
            rank[i]=0;
        }
    }
    int find(int x) {
        if(par[x]==x) {
            return x;
        }else {
            return par[x]=find(par[x]);
        }
    }
    void unite(int x,int y) {
        x=find(x);
        y=find(y);
        if(x==y) return;
        if(rank[x]<rank[y]) {
            par[x]=y;
        }else {
            par[y]=x;
            if(rank[x]==rank[y]) rank[x]++;
        }
    }
    bool same(int x,int y) {
        return find(x)==find(y);
    }
};
int ans[100000];
int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    UnionFind U(n);
    int k=0;
    for(int i=0;i<q;i++) {
        int com,x,y;
        scanf("%d %d %d",&com,&x,&y);
        if(com==0) {
            U.unite(x,y);
        }else {
            ans[k++]=U.same(x,y);
        }
    }
    for(int i=0;i<k;i++) {
        printf("%d\n",ans[i]);
    }
}