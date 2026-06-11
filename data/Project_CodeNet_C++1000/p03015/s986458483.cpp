#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;

ll dp[100001][2] = {};

int main(){
    int n, i, j;
    string l;
    cin >> l;
    n = l.length();
    dp[i][0] = 1;
    for(i=0; i<n; i++){
        if(l[i] == '0'){
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = 3*dp[i][1]%MOD;
        }else{
            dp[i+1][0] = 2*dp[i][0]%MOD;
            dp[i+1][1] = (3*dp[i][1] + dp[i][0])%MOD;
        }
    }
    cout << (dp[n][0]+dp[n][1])%MOD << "\n";
    return 0;
}