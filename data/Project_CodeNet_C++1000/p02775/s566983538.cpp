#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    
    int l= (int)(s.length());
    
    int dp[l][2];
    int a = s[0] - '0';
    dp[0][0] = a;
    dp[0][1] = 10 - a;

    for (int i=1; i<l; i++){
        a = s[i] - '0';
        dp[i][0] = min(dp[i-1][0] + a, dp[i-1][1] + a+1);
        dp[i][1] = min(dp[i-1][0] + 10 - a, dp[i-1][1] + 10 - (a+1));
    }


    cout << min(dp[l-1][0], dp[l-1][1]+1) << endl;

  }