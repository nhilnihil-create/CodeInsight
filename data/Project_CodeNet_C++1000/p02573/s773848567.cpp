#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)

// Union Find木
// https://atcoder.jp/contests/atc001/tasks/unionfind_a

struct UnionFind{

    // 親:子の数*(-1)
    // 子:親の番号,par[子の番号] = 親の番号 となる

    vector<int> par;

    // すべてのノードを，根(-1)として初期化
    UnionFind(int N){
        par = vector<int>(N,-1);
    }

    // データxが属する根を再帰で取得
    int root(int x){
        if(par[x] < 0) return x;
        return par[x] = root(par[x]);
    }

    // x,yの木を併合
    bool unite(int x,int y){
        int root_x = root(x);
        int root_y = root(y);
        // xとyが同じ木に属していた場合
        if(root_x == root_y) return false;
        // 小さな木を大きい木に併合する
        if(par[root_x] > par[root_y]) swap(root_x,root_y);
        par[root_x] += par[root_y];
        par[root_y] = root_x;
        return true;
    }

    int size(int x){
        return -par[root(x)];
    }
};

int main(void){
    ll N,M;
    cin >> N >> M;

    int ans = 0;
    UnionFind Trees(N);

    REP(i,M){
        int A,B;
        cin >> A >> B;
        A --; B --;
        Trees.unite(A,B);
    }

    REP(i,N){
        ans = max(ans,Trees.size(i));
    }

    cout << ans << endl;

    return 0;
}