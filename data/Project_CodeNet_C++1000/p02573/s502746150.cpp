#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define debug(output) cout<<#output<<"= "<<output<<endl
using lint=long long;
int MOD=1000000007;
struct UnionFind {
    int n;
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> group;
    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
        n=N;
    }
    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    void calc(){
        group.resize(n,0);
        for(int i=0;i<n;i++){
            group[root(i)]++;
        }
    }
    int size(int x){
        return group[root(x)];
    }
    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }
 
    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
 
};

signed main(){
    int n,m;cin>>n>>m;
    UnionFind tree(n+1);
    rep(i,m){
        int a,b;cin>>a>>b;
        tree.unite(a,b);
    }
    tree.calc();
    int res=0;
    rep1(i,n){
        res=max(res,tree.group[i]);
    }
    cout<<res<<"\n";
    return 0;
}