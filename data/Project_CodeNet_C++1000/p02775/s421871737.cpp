#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5, mod = 1e9 + 7;

string s;
int n, dp[N][2];


int solve(int idx, bool b){
    if(idx == n) return b;
    if(~dp[idx][b]) return dp[idx][b];
    int op1 = solve(idx + 1, 0) + s[idx] - '0' + b;
    int op2 = 10 - b - (s[idx] - '0') + solve(idx + 1, 1);
    return dp[idx][b] = min(op1, op2);
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s;
    reverse(s.begin(), s.end());
    n = s.size();
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0);

    return 0;
}
