#include <bits/stdc++.h>   
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
     
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}
using Graph = vector<vector<int>>;
Graph G;
/*------------------------------------------------------------------*/
int main(){
    int n, x, y; cin >> n >> x >> y;
    x--, y--;
    vector<vector<int>> dp(n, vector<int>(n));
    rep(i, n)rep(j, n) dp[i][j] = abs(i - j);
    rep(i, n){
        rep(j, n){
            dp[i][j] = min(dp[i][j], dp[i][x] + dp[y][j] + 1);
            dp[i][j] = min(dp[i][j], dp[i][y] + dp[x][j] + 1);
        }
    }
    vector<int> ans(n, 0);
    rep(i, n)_rep(j, i + 1, n) ans[dp[i][j]]++;
    _rep(i, 1, n) cout << ans[i] << endl;   
}