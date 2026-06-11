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
    dp[0][0] = 1;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '?'){
            for(int j=0; j<10; j++){
                for(int k=0; k<13; k++){
                    int ind = (k*10+j) % 13;
                    dp[i+1][ind] = (dp[i][k]+dp[i+1][ind]) % mod;
                }
            }
        }
        else{
            for(int j=0; j<13; j++){
                int x = s[i]-'0';
                int ind = (j*10+x)%13;
                dp[i+1][ind] = (dp[i][j]+dp[i+1][ind]) % mod;
            }
        }
    }

    lli ans = dp[s.size()][5];

    cout << ans << "\n";

    return 0;
}
