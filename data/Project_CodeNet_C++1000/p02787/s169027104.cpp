#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3 + 5, M = 1e4 + 5, mod = 1e9 + 7;

int dp[N][M], mark[N][M], n, h, dam[N], cost[N];

ll solve(int idx, int kam){
    if(kam <= 0) return 0;
    if(idx == n) return 1e9;
    if(mark[idx][kam]) return dp[idx][kam];
    mark[idx][kam] = 1;
    int op1 = cost[idx] + solve(idx, kam - dam[idx]);
    int op2 = solve(idx + 1, kam);
    return dp[idx][kam] = min(op1, op2);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> h >> n;
    for(int i = 0; i < n; i++){
        cin >> dam[i] >> cost[i];
    }
    cout << solve(0, h);

    return 0;
}
