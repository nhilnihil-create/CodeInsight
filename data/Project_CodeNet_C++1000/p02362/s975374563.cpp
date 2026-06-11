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
using vll = vector<long long>;
using pll = pair<long long, long long>;
#define rep(i,n) for(long long i(0);(i)<(n);(i)++)
ll INF = 1LL << 60;

struct edge{
    ll to;
    ll cost;
    edge(ll t, ll c){
        to = t;
        cost = c;
    }
};

struct fulledge{ //* u->v with cost
    ll u, v, cost;
    fulledge(){}
    fulledge(ll _u, ll _v, ll _c){
        u = _u; v = _v; cost = _c;
    }

    bool operator< ( fulledge const &e) const {
        return cost < e.cost;
    }
};

struct edgeGreater{
    bool operator()(const fulledge &e1, const fulledge &e2){
        return e1.cost > e2.cost;
    }
};

//* simplest bellman-ford shortest path calculator
bool BellmanFord(vector<fulledge> &es, vector<ll> &dist, ll s){
    ll N = dist.size();
    ll M = es.size();
    fill(dist.begin(), dist.end(), INF);
    dist[s] = 0;
    bool update;
    rep(k, N){
        update = false;
        rep(i, M){
            fulledge e = es[i];
            if(dist[e.u]!=INF && dist[e.v] > dist[e.u]+e.cost) {
                dist[e.v] = dist[e.u] + e.cost;
                update = true;
            }
        }
        if(!update) 
            break;
    }
    return update;
}
//* http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=jp
int main(){
    ll N, M, s;
    cin >> N >> M >> s;
    vector<fulledge> es;
    ll u, v, c;
    rep(i, M){
        cin >> u >> v >> c;
        es.push_back(fulledge(u, v, c));
    }
    vector<ll> dist(N);
    bool isBad = BellmanFord(es, dist, s);
    if(isBad)
        cout << "NEGATIVE CYCLE" << endl;
    else{
        rep(i, N){
            if(dist[i]>= INF) 
                cout << "INF" << endl;
            else{
                cout << dist[i] << endl;
            }
        }
    }

    return 0;
}
