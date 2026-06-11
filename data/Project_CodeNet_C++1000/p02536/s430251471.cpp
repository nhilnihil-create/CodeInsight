#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

struct UnionFind{
private:
    vector<int> par;
    vector<int> siz;
public:
    void init(int N){
        par.resize(N);
        siz.resize(N);
        for(int i=0; i<N; i++) par[i] = i;
        for(int i=0; i<N; i++) siz[i] = 1;
    }
    void unite(int a, int b){
        int rootA = root(a);
        int rootB = root(b);
        if(rootA == rootB) return;
        if(siz[rootA] < siz[rootB]) swap(rootA, rootB);
        par[rootB] = rootA;
        siz[rootA] += siz[rootB];
    }
    int root(int a){
        if(par[a] == a) return a;
        return par[a] = root(par[a]);
    }
    bool same(int a, int b){
        return root(a) == root(b);
    }
    int size(int a){
        return siz[root(a)];
    }
};

int N, M;
UnionFind uf;

signed main(){
    cin >> N >> M;
    uf.init(N);
    rep(i, M){
        int a, b;
        cin >> a >> b;
        uf.unite(a-1, b-1);
    }

    int ans = 0;
    rep(i, N){
        if(uf.root(i) == i) ans++;
    }
    cout << ans-1 << endl;
}