#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const int N = 1e5 + 5;
int n, k, r, s, p;
string t, play = "rspt";
ll dp[N][5];
ll score(char a, char b){
    if(a == 'r' && b == 'p') return p;
    else if(a == 's' && b == 'r') return r;
    else if(a == 'p' && b == 's') return s;
    else return 0;
}
ll solve(int idx, int prev){
    if(idx >= n) return 0;
    if(dp[idx][prev] != -1) return dp[idx][prev];
    ll ans = 0;
    for(int i = 0; i < 3; i++)
        if(i != prev)
            ans = max(ans, solve(idx + k, i) + score(t[idx], play[i]));
    dp[idx][prev] = ans;
    return dp[idx][prev];
}
int main(){
    Hello
    cin >> n >> k >> r >> s >> p >> t;
    ll ans = 0;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < k; i++) ans += solve(i, 3);
    cout << ans;
    return 0;
}