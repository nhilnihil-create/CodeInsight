#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int path[505][505] = {};

void solve(vector<int> v, int lev){
    if(v.size() == 1) return;
    vector<int> w, x;
    rep(j,v.size()){
        if(j%2) x.push_back(v[j]);
        else w.push_back(v[j]);
    }
    rep(i,w.size()){
        rep(j,x.size()){
            path[w[i]][x[j]] = lev;
            path[x[j]][w[i]] = lev;
        }
    }
    solve(w, lev+1);
    solve(x, lev+1);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v;
    rep(i,n) v.push_back(i+1);
    solve(v, 1);
    rep(i,n){
        for(int j = i+2; j <= n; ++j){
            cout << path[i+1][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
