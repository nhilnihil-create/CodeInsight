#include<iostream>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm> 
#include<climits>
#include<stack>
#include<queue>
#include<set>
#include<cctype>
using namespace std;

struct UnionFind {
    vector<int> par;
    vector<int> sz;
    map<int, int> szmp; // map<size, cnt>
 
    // n : 要素数
    UnionFind(int n = 0){
        if(n > 0) initialize(n);
    }
 
    void initialize(int n){
        par.resize(n);
        sz.resize(n);
        for(int i = 0; i < n; i++){
            par[i] = i;
            sz[i] = 1;
        }
        szmp[1] = n;
    }
 
    // 0-index
    int find(int x){
        if(par[x] == x){
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    // 0-index
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(sz[x] > sz[y]) swap(x, y);
 
        for(int s : {sz[x], sz[y]}){
            szmp[s]--;
            if(szmp[s] == 0) szmp.erase(s);
        }
        par[x] = y;
        sz[y] += sz[x];
        szmp[sz[y]]++;
    }
 
    // 0-index
    bool same(int x, int y){
        return find(x) == find(y);
    }

    // 0-index
    int size(int x){
        return sz[find(x)];
    }
 
    // 最小要素サイズ
    int minsz(){
        return szmp.begin() -> first;
    }

    // 連結成分個数
    int unitenum(){
        int ret = 0;
        for(auto u : szmp){
            ret += u.second;
        }
        return ret;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    UnionFind uf(n);

    while(m--){
        int a, b;
        cin >> a >> b;
        uf.unite(a-1, b-1);
    }
    cout << uf.unitenum() - 1 << endl;
    return 0;
}
