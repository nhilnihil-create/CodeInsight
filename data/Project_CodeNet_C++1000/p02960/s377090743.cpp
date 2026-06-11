#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;cin>>s;
    int n=s.size();
    int mod=1e9+7;
    ll dp[n+1][13]{};
    dp[0][0]=1;
    for (int i=0;i<n;i++)
        for (int j=0;j<13;j++)
            for (int k=0;k<=9;k++)
                if (s[i]=='?'||s[i]-'0'==k)
                    dp[i+1][(j*10+k)%13]=(dp[i+1][(j*10+k)%13]+dp[i][j])%mod;
    cout<<dp[n][5]<<endl;
    return 0;
}