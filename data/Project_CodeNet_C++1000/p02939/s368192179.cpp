#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define V vector<int>
#define ll long long
using namespace std;


int main() {

    string S;
    cin >> S;

    int n = S.size();

    //n = 1 のとき
    if(n == 1) {
        cout << "1\n";
        return 0;
    }

    //n = 2 のとき
    if(n == 2) {
        if(S[0] == S[1]) cout << "1\n";
        else cout << "2\n";
        return 0;
    }

    //n = 3 のとき
    if(n == 3) {
        if(S[0] != S[1] && S[1] != S[2]) cout << "3\n";
        else cout << "2\n";
        return 0;
    }

    int dp[n];

    //n = 1
    dp[0] = 1;

    //n = 2
    if(S[0] == S[1]) dp[1] = 1;
    else dp[1] = 2;

    //n = 3
    if(S[0] != S[1] && S[1] != S[2]) dp[2] = 3;
    else dp[2] = 2;

    rep(i, 3, n){
        if(S[i] == S[i-1]) dp[i] = dp[i-3] + 2;
        else dp[i] = dp[i-1] + 1;
    }

    cout << dp[n-1] << "\n";
} 
