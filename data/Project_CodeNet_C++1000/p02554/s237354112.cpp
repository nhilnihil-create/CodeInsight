#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5, mod = 1e9 + 7;

int n, dp[N][2][2], vis[N][2][2];

ll add(ll a, ll b){
    a = (a + mod) % mod;
    b = (b + mod) % mod;
    return (a + b) % mod;
}

ll mul(ll a, ll b){
    a = (a + mod) % mod;
    b = (b + mod) % mod;
    return (a * b) % mod;
}

ll solve(int idx, bool x, bool y){
    if(idx == n) return (x + y == 2);
    if(vis[idx][x][y]) return dp[idx][x][y];
    vis[idx][x][y] = 1;
    ll op1 = solve(idx + 1, x, y);
    ll op2 = solve(idx + 1, 1, y);
    ll op3 = solve(idx + 1, x, 1);
    op1 = mul(8, op1);
    return dp[idx][x][y] = add(op1, add(op2, op3));
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    cout << solve(0, 0, 0);



    return 0;
}
