#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const long long mod = 1e9+7;

int main(){
    int  n, m; cin >> n >> m;
    
    vector<bool> stairs(n+1, true);
    for(int i=0; i<m; i++){
        int a; cin >> a;
        stairs[a] = false;
    }

    vector<ll> dp(n+1);
    dp[0]=1;
    for(int i=0; i<n; i++){
        int MIN = min(n, i+2);
        for(int j=i+1; j<=MIN; j++){
            if(stairs[j]){
                dp[j]+=dp[i];
                dp[j]%=mod;
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}   