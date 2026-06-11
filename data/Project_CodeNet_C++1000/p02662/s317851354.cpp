#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll dp[4000][4000];

int main()
{
    int n,s;
    cin>>n>>s;
    vector<int>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    dp[0][0]=1;
    for(int i=1;i<=n;++i){
        for(int j=0;j<=s;++j){
            dp[i][j]=dp[i-1][j]*2;
            if(j-a[i-1] >= 0)dp[i][j]+=dp[i-1][j-a[i-1]];
            dp[i][j]%=998244353;
        }
    }
    cout<<dp[n][s]<<endl;
}