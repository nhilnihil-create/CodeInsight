#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <assert.h>
#include <unordered_set>
#include <random>
#include <atcoder/all>


using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;


#define REP(i, n) for(ll i = 0; i < n; i++)





















class Unionfind {
private:
    vector<int> par;
    vector<int> rank;
    vector<int> counter;
    
public:
    Unionfind(int n) : rank(n), counter(n, 1){
        for(int i = 0; i < n; i++){
            par.push_back(i);
        }
    }
    
    int find(int x){
        if (par[x] == x) {
            return x;
        }
        else {
            return par[x] = find(par[x]);
        }
    }
    
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if (x == y) return;
        
        if (rank[x] < rank[y]) {
            counter[y] += counter[x];
            counter[x] = counter[y];
            par[x] = y;
        }
        else {
            counter[y] += counter[x];
            counter[x] = counter[y];
            par[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }
    
    bool same(int x, int y){
        return find(x) == find(y);
    }
    
    ll count(int x){
        return counter[find(x)];
    }
};

int main(){
    ll n, q;
    cin >> n >> q;
    Unionfind uni(n);
    REP(i, q){
        ll t, u, v;
        cin >> t >> u >> v;
        if(t == 0){
            uni.unite(u, v);
        }
        else{
            cout << uni.same(u, v) << endl;
        }
    }
}