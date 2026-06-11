#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using ll = long long;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n);
    dp[n-1] = s[n-1] - '0';
    int t = 10;
    for(int i = 2; i <= n; i++){
        dp[n-i] = ((s[n-i] - '0')*t + dp[n-i+1]) % 2019;
        t *= 10;
        t %= 2019;
    }

    int ans = 0;
    for(int i = 0; i < 2019; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(dp[j] == i) cnt++;
        }
        ans += cnt*(cnt-1)/2;
        if(i == 0) ans += cnt;
    }
    
    cout << ans << endl;
}