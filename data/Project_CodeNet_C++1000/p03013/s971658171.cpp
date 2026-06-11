#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N; i >= 0; i--)
const ll INF = 1000000007;
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
ll dp[100050];
int main(){
    int N,M;
    cin >> N >> M;
    vector<int> a(M);
    vector<bool> b(100050,true);
    rep (i,M) {
        cin >> a.at(i);
        b.at(a.at(i)) = false;
    }
    dp[0] = 1;
    if (b.at(1)) dp[1] = 1;
    for (int i = 2; i <= 100010; i++) {
        if (b.at(i)) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        dp[i] %= INF;
    }
    cout << dp[N] << endl;
    return 0;
}
