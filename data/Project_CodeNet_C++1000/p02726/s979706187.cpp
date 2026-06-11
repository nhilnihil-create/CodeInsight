#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

template<typename T>
istream& operator>> (istream& is, vector<T> &vec){
    for(T& x: vec) is >> x;
    return is;
}

vector<ll> search(ll i, vector<vector<ll>> &g){
    vector<ll> dist(g.size(), -1);
    queue<ll> que;

    dist[i] = 0;
    que.push(i);

    while(!que.empty()){
        ll v = que.front();
        que.pop();

        for(int nv : g[v]){
            if(dist[nv] != -1) continue;

            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
    return dist;
}

int main(){
    ll n, x, y; cin >> n >> x >> y;
    vector<vector<ll>> g(n);
    rep(i, n-1){
        g[i].push_back(i+1);
        g[i+1].push_back(i);
    }
    g[x-1].push_back(y-1);
    g[y-1].push_back(x-1);

    vector<ll> hops(n, 0);
    for(ll i = 0; i < n; ++i){
        vector<ll> hop = search(i, g);
        for(auto i : hop){
            hops[i]++;
        }
    }
    rep(i, hops.size()){
        if(i == 0) continue;
        cout << hops[i]/2 << endl;
    }
    return 0;
}