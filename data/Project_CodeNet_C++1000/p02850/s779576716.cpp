//---------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <sstream>
#include <numeric>
#include <cctype>
#include <bitset>
#include <cassert>
//---------------------------------------------------------------
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define SIZE 100005
#define INF 1000000000000000LL
#define all(x) x.begin(),x.end()
using pint = pair<int,int>;
using vec = vector<int>;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
//---------------------------------------------------------------
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//---------------------------------------------------------------

//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

    using Graph = vector<vector<pint>>;
    int n;
    Graph G;

    void dfs(int v, int p, int pc, vec &res){
        int color = 1;
        if(color == pc) ++color;
        for(auto e : G[v]) {
            if(e.first == p) continue;
            res[e.second] = color;
            dfs(e.first, v ,color, res);
            ++color;
            if(color == pc) ++color;
        }
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    G.assign(n, vector<pint>());
    rep(i,n-1){
        int a,b;cin>>a>>b;
        --a;--b;
        G[a].emplace_back(b,i);
        G[b].emplace_back(a,i);
    }

    int max_color = 0; 
    rep(i,n){
        chmax(max_color, (int)G[i].size());
    }

    vec res(n-1, -3);
    dfs(0, -3, -3, res);
    cout<<max_color<<endl;
    for(auto v : res) cout << v << endl;

}