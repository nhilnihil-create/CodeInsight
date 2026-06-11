#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
static const ull MOD = 1e9 + 7;

int n;
char s[100005];
ull dp[100005][13];

int main()
{
    scanf("%s", s);
    n = strlen(s);
    //cout << "n:" << n << endl;
    dp[0][0] = 1;
    for(int i = 0; i < n; ++i) {

        /*
        for(int j = 0; j < 13; ++j) {
            for(int i = 0; i < n+1; ++i) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        */

        int c;
        if(s[i] =='?') c = -1;
        else c = s[i] - '0';

        for(int j = 0; j < 10; ++j) {
            if(c != -1 && c != j) continue;
            for(int ki = 0; ki < 13; ++ki) {
                dp[i+1][(ki*10 + j)%13] += dp[i][ki];
            }
        }
        for(int j = 0; j < 13; ++j) dp[i+1][j] %= MOD;
    }

    cout << dp[n][5] << endl;
}
