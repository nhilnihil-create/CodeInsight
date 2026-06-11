#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

void swap(int &x, int &y){
    int tmp = x;
    x = y;
    y = tmp;
    return;
}

struct UnionFind{
    vi par;
    UnionFind(int n){
        par = vi(n, -1);
    }
    int root(int x){
        if(par[x] < 0) return x;
        return par[x] = root(par[x]);
    }
    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return;
    }
    int size(int x){
        return -par[root(x)];
    }
};

int main(void){
    int n, m;
    cin >> n >> m;
    UnionFind UF(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a -= 1; b -= 1;
        UF.unite(a, b);
    }
    int v = 0;
    for(int i=0; i<n; i++){
        if(v < UF.size(i)) v = UF.size(i);
    }
    cout << v << '\n';
    return 0;
}