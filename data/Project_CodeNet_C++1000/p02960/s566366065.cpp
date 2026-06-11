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

ll dp[100010][13]; // pos, value:mod 13
int main(){
    string s; cin >> s;
    int n = s.size();
    int k; cin >> k;

    rep(i, 100010)rep(j, 13) dp[i][j] = 0;
    dp[0][0] = 1;
    rep(i, n)rep(j, 13){
        if(s[i] == '?'){
            rep(d, 10){
                (dp[i + 1][(j * 10 + d) % 13] += dp[i][j]) %= mod;
            }
        }else{
            (dp[i + 1][(j * 10 + (s[i] - '0')) % 13] += dp[i][j]) %= mod;
        }
    }
    ll ans = dp[n][5];
    cout << ans << endl;
    return 0;
}