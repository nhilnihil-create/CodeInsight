#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define INF 100000000000
#define MAX 200001
#define MOD 998244353

void dfs(int s, Graph &G, vector<int> &visited, vector<ll> &cnt){
    visited[s] = 1;
    cnt[(s - 1) / 100000] += 1;
    for(auto v: G[s]){
        if(visited[v]) continue;
        dfs(v, G, visited, cnt);
    }
}

int main(){
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(S + 1, 0));
    dp[0][0] = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= S; j++){
            if(j - A[i] >= 0){
                dp[i + 1][j] += dp[i][j - A[i]];
                dp[i + 1][j] %= MOD;
            }
            dp[i + 1][j] += 2 * dp[i][j];
            dp[i + 1][j] %= MOD;
        }
    }
    cout << dp[N][S] << endl;
}