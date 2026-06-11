#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const int N = 1e5 + 5, mod = 1e9 + 7;
bool step[N];
int n, m, dp[N];
ll solve(int idx){
    if(idx > n || (step[idx] == false)) return 0;
    if(idx == n) return 1;
    if(dp[idx] != -1) return dp[idx];
    ll ans = 0;
    ans = (ans + (solve(idx + 1) % mod)) % mod;
    ans = (ans + (solve(idx + 2) % mod)) % mod;
    dp[idx] = ans;
    return dp[idx];
}
int main(){
    Hello
    cin >> n >> m;
    for(int i = 0; i < N; i++) step[i] = true;
    for(int i = 0, a; i < m; i++){
        cin >> a;
        step[a] = false;
    }
    memset(dp, -1, sizeof dp);
    cout << solve(0);
    return 0;
}
