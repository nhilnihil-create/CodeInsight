// ABC135-D Digits Parade

#include <bits/stdc++.h>
using namespace std;

#define MOD (1000000007)

void add(long long &a, long long b);

signed  main() {
    string s;
    cin >> s;
    vector<vector<long long>> dp(s.size()+1, vector<long long>(13, 0));

    dp[0][0] = 1;
    for (int i=0 ;i<s.size() ;i++ ) {
        for(int j=0 ;j<13 ;j++ ) {
            if (s[i] == '?') {
                for (int k=0 ;k<10 ;k++ ) {
                    add(dp[i+1][(j*10+k)%13], dp[i][j]);
                }
            }
            else {
                int k = s[i] - '0';
                add(dp[i+1][(j*10+k)%13], dp[i][j]);
            }
        }
    }

    cout << dp[s.size()][5] << '\n';

    return (0);
}

void add(long long &a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
}