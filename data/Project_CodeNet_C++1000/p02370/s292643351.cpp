#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <random>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using qll = queue<ll>;
using vb = vector<bool>;
using mll = map<ll, ll>;
using sll = stack<ll>;
#define REP(i,n) for(ll i(0);(i)<(n);(i)++)
#define rep(i,n) for(ll i(0);(i)<(n);(i)++)
#define ALL(a) a.begin(), a.end()
#define enld endl //* missspell check
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

struct TopologicalSort{
    vector<vll> G; //* DAG
    TopologicalSort(ll N){ G.resize(N); }
    void add_edge(ll a, ll b) { G[a].push_back(b); }
    bool visit_by_dfs(vll &order, vll &color, ll v) {
        //* color[v] meaning: 0: unvisited, 1: pre-visit, 2: post-visit
        //! return false if this graph has a cycle
        color[v] = 1; //* pre-visit this vertex
        for(auto u: G[v]) {
            if(color[u] == 2) continue; //* this vertex is done (already put in order)
            if(color[u] == 1) return false; //* re-visit this vertex means a cycle
            if(!visit_by_dfs( order, color, u)) return false; //* a cycle detected further
        }
        order.push_back(v);
        color[v] = 2;
        return true;
    }
    bool sort(vll &order) {
        //! return false if this graph has a cycle
        ll n = G.size();
        vll color(n, 0);
        REP(u, n) if( !color[u] && !visit_by_dfs(order, color, u)) return false;   
        reverse(order.begin(), order.end()); 
        return true;
    }
};

int main(){
    ll N, M; cin >> N >> M;
    TopologicalSort st(N);
    REP(_, M){
        ll u, v; cin >> u >> v;
        st.add_edge(u, v);
    }
    vll order;
    st.sort(order);
    REP(i, N) cout<< order[i] << endl;
    return 0;
}

