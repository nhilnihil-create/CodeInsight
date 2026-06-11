#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> pow2(13, 1);
    for(int i=1; i<13; i++){
        pow2[i] = pow2[i-1] * 2;
    }

    vector<int> a(m), bc(m);    
    for(int i=0; i<m; i++){
        int b;
        cin >> a[i] >> b;
        for(int j=0; j<b; j++){
            int c;
            cin >> c;
            c -= 1;
            bc[i] += pow2[c];
        }
    }

    vector<vector<int>> dp(m+1, vector<int>((1<<n), INF));
    dp[0][0] = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<(1<<n); j++){
            dp[i+1][(j|bc[i])] = min(dp[i+1][(j|bc[i])], dp[i][j] + a[i]);
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
        }
    }
    /*
    for(int i=0; i<=m; i++){
        for(int j=0; j<(1<<n); j++){
            if(dp[i][j] == INF) cout << setw(5) << "INF";
            if(dp[i][j] != INF) cout << setw(5) << dp[i][j];
            cout << " ";
        }
        cout << endl;
    }
    */

    if(dp[m][(1<<n)-1] != INF) cout << dp[m][(1<<n)-1] << endl;
    if(dp[m][(1<<n)-1] == INF) cout << -1 << endl;
    return 0;
}