#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n, m;
    cin >> n >> m;
    
    vector<int> nomal(n+1,1);
    
    for (int i = 0; i < m; i++){
        int a;
        cin >> a;
        nomal[a] = 0;
    }
    
    vector<int> dp(n+2);
    const int mod = 1e9+7;
    
    dp[0] = 1; // 0段目までの移動方法は,移動しないという0通り
    
    for (int now= 0; now < n; now++){
        for (int next = now+1; next <= min(n,now+2);next++){
            
            if (nomal[next]){
                dp[next] += dp[now];
                dp[next] %= mod;
            }
        }
    }
    
    cout << dp[n] << endl;
    return 0;
}