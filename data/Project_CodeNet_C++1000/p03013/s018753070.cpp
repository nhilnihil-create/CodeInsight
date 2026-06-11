#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void){
    ll N,M;
    cin >> N >> M;
    
    vector<bool> vec(110000,true);
    vector<ll> dp(110000,0);
    
    for(int i = 0; i < M; i++){
        ll a;
        cin >> a;
        vec[a] = false;
    }
    
    dp[0] = 1;
    for(int i = 1; i <= N; i++){
        if(i == 1){
            if(vec[i] == true){
                dp[i] = 1;
            }
            continue;
        }
        
        if(vec[i-1] == true) dp[i] += dp[i-1];
        if(vec[i-2] == true) dp[i] += dp[i-2];
        dp[i] %= 1000000007;
    }
    
    cout << dp[N] << endl;
}