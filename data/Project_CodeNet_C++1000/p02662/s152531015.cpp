#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e3 + 5, mod = 998244353;

int n, s, a[N], dp[N][N];

int add(int a, int b){
    a = (a + mod)%mod;
    b = (b + mod) % mod;
    return (a + b) % mod;
}

int mul(int a, int b){
    a = (a + mod) % mod;
    b = (b + mod) % mod;
    return 1LL * a * b % mod;
}

int solve(int idx, int sum){
    if(idx == n) return (sum == s);
    if(dp[idx][sum] != -1) return dp[idx][sum];
    int op1 = 0, op2 = 0;
    op1 = mul(2, solve(idx + 1, sum));
    if(sum + a[idx] <= s) op2 = solve(idx + 1, sum + a[idx]);
    return dp[idx][sum] = add(op1, op2);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0);


    return 0;

}
