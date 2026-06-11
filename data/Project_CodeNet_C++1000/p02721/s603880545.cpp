#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k, c;
    cin >> n >> k >> c;
    c++;
    vector<char>s(n + 3);
    vector<int>dp(n + 3), dp2(n + 3);
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i - 1];
        if(s[i] == 'o'){
            int idx = max(i - c, 0);
            dp[i] = max(dp[i], dp[idx] + 1);
        }
    }
    if(dp[n] != k){
        return 0;
    }
    dp2[n + 1] = 0;
    for(int i = n; i >= 1; i--){
        dp2[i] = dp2[i + 1];
        if(s[i] == 'o'){
            int idx = min(i + c, n + 1);
            dp2[i] = max(dp2[i], dp2[idx] + 1);
        }
    }
    vector<int>ans;
    for(int i = 1; i <= n; i++){
        if(s[i] == 'o' && dp[i] > dp[i - 1] && dp2[i] > dp2[i + 1]){
            ans.push_back(i);
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << '\n';
    }
    return 0;
}