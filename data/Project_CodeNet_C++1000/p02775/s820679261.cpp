#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int const N = 1e6 + 1;
int dp[N][2], n;
string s;

int solve(int i, int cima){
    if (dp[i][cima] != -1) return dp[i][cima];
    if (i == n-1){
        if (cima) return dp[i][cima] = 10 - s[i];
        return dp[i][cima] = s[i];
    }
    if (cima) return dp[i][cima] = min(solve(i+1, 1) + 10 - (s[i] + 1), solve(i+1, 0) + 10 - s[i]);
    return dp[i][cima] = min(solve(i+1, 1) + s[i] + 1, solve(i+1, 0) + s[i]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    n = s.size();
    for (int i=0; i<n; i++) s[i] -= '0';
    memset(dp, -1, sizeof dp);

    cout << min(solve(0, 0), 1 + solve(0, 1)) << endl;
    
}