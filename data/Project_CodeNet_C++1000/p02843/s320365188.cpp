#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N; i >= 0; i--)
const ll INF = 1000000000000000000;
#define PI 3.1415926535
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
bool seen[100000];
void dfs(const Graph &G, int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}

//dpTable
bool dp[100050];
int main(){
    int X;
    cin >> X;
    rep (i,106) {
        if (i == 0 || i == 100 || i == 101 || i == 102 || i == 103 || i == 104 || i == 105) dp[i] = true;
        else dp[i] = false;
    }
    for (int i = 106; i <= 100000; i++) {
        if (dp[i - 100] || dp[i - 101] || dp[i - 102] || dp[i - 103] || dp[i - 104] || dp[i - 105]) dp[i] = true;
        else dp[i] = false;
    }
    cout << (dp[X] ? 1 : 0) << endl;
    return 0;
}