#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;


int main(){
    int N; ll K; 
    cin >> N >> K;
    vector<vector<int>> next(60, vector<int>(N));
    rep(v,N) cin >> next[0][v], next[0][v]--;
    rep(d,59){
        rep(v, N){
            next[d+1][v] = next[d][next[d][v]];
        }
    }
    int v = 0;
    for(int d = 0; d < 60; d++){
        if(K & (1LL << d)) v = next[d][v];
    }
    cout << v + 1 << endl;
}