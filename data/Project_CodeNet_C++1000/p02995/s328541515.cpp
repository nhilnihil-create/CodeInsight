#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N; i >= 0; i--)
const ll INF = 1000000000;
const ll mod = 1000000007;
#define PI 3.1415926535
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
typedef pair<int, int> pair;
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
int dp[100050];

int main(){
    ll A,B,C,D;
    cin >> A >> B >> C >> D;
    ll E = C * D  / __gcd(C,D);
    ll F = B / C - (A - 1) / C;
    ll G = B / D - (A - 1) / D;
    ll H = B / E - (A - 1) / E;
    cout << B - A + 1 - F - G + H << endl;
    return 0;
}
