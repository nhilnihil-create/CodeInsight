#include<bits/stdc++.h>
using namespace std;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<lli, lli> pi;

lli dp[100020][15], mod = 1000000007;

int main()
{
    string s;
    cin >> s;
    if(s[0] == '?'){
        for(int i=0; i<10; i++){
            dp[0][i] = 1;
        }
    }
    else{
        int ind = s[0] - '0';
        dp[0][ind] = 1;
    }
    for(int i=1; i<s.size(); i++){
        if(s[i] == '?'){
            for(int j=0; j<13; j++){
                for(int k=0; k<10; k++){
                    int ind = (j*10+k) % 13;
                    dp[i][ind] = (dp[i-1][j]+dp[i][ind]) % mod;
                }
            }
        }
        else{
            for(int j=0; j<13; j++){
                int ind = s[i] - '0';
                ind += j*10;
                ind %= 13;
                dp[i][ind] = (dp[i-1][j]+dp[i][ind]) % mod;
            }
        }
    }

    cout << dp[s.size()-1][5] << "\n";

    return 0;
}
