#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void){
    ll N,M;
    cin >> N >> M;
    
    vector<bool> vec(100100,true);
    for(int i = 0; i < M; i++){
        ll tmp;
        cin >> tmp;
        vec[tmp] = false;
    }
    
    vector<ll> dp(100100,0);
    dp[0] = 1;
    for(int i = 0; i < N; i++){
        if(vec[i+1] == true) dp[i+1] += dp[i];
        if(vec[i+2] == true) dp[i+2] += dp[i];
        dp[i+1] %= 1000000007;
    }
    
    cout << dp[N] << endl;
}