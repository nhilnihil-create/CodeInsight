#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    if(n == 2){
        if(s[0] == s[1]){
            cout << 1 << endl;
        }
        else{
            cout << 2 << endl;
        }
        return 0;
    }
    int dp[n]{0};
    dp[0] = 1;
    if(s[0] == s[1]){
        dp[1] = 1; 
    }
    else{
        dp[1] = 2;
    }
    if(s[0] != s[1] && s[1] != s[2]){
        dp[2] = 3;
    }
    else{
        dp[2] = 2;
    }
    for(int i = 3;i < n;i++){
        if(s[i-1] == s[i]){
            dp[i] = dp[i-3] + 2;
        }
        else{
            dp[i] = dp[i-1] + 1;
        }
    }
    cout << dp[n-1] << endl;
}