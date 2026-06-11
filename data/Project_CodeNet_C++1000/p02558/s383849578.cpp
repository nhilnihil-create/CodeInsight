#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>

#define ll long long
#define REP(i,n) for(int i = 0; i < (n); ++i)
#define PI 3.141592653589
#define MOD 1000000007

using namespace std;

template<typename T> T gcd(T a, T b){ return (a % b)? gcd(b, a%b) : b; }
template<typename T> T lcm(T a, T b){ return a * b / gcd(a, b); }

class UnionFind{
    public:
    vector<int> par;
    UnionFind(int N) : par(N){
        REP(i,N) par[i] = i;
    }

    int root(int x){
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        par[x] = y; 
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }
};

int main(void){
    int n, q;
    cin >> n >> q;
    
    UnionFind uf(n);
    REP(i,q){
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 0){
            uf.unite(u, v);
        } else{
            cout << uf.same(u, v) << endl;
        }
    }
    
    return 0;
}