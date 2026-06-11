//ACL Beginners Contest C

#include<iostream>
#include<vector>
using namespace std;

class UnionFind {
private:
    vector<int> par; // 親ノード
    vector<int> rank; // ランク
    void init(int n = 1) {
        par.resize(n); rank.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0;
    }
public:
    UnionFind(int n = 1) {
        init(n);
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            return par[x] = r;
        }
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        return true;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    UnionFind uf(n);
    int res=n-1;
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        --a,--b;
        if(uf.merge(a,b)) --res;
    }

    cout<<res<<endl;
}