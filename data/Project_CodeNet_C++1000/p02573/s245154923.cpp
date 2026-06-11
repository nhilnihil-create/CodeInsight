#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

class UnionFind {
    vector<int> data;
    ll num;
public:
    UnionFind(int size) : data(size, -1), num(size) { }
    bool unite(int x, int y) {//xとyの集合を統合する
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        num -= (x != y);
        return x != y;
    }
    bool findSet(int x, int y) {//xとyが同じ集合か返す
        return root(x) == root(y);
    }
    int root(int x) {//xのルートを返す
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    ll size(int x) {//xの集合のサイズを返す
        return -data[root(x)];
    }
    ll numSet() {//集合の数を返す
        return num;
    }
};
 int main(){
ll n,m;
   cin>>n>>m;
   UnionFind uf(n);
   rep(i,m){
     ll a,b;
     cin>>a>>b;
     a--;b--;
   uf.unite(a,b);
   }
   ll ans=0;
   rep(i,n){
     ans=max(ans,uf.size(i));
   }
   cout<<ans<<endl;
}

     
