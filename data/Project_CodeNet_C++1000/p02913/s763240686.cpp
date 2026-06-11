#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int main(void){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int> > dp(n+1, vector<int>(n+1));
    int ans=0;
    for(int i=1;i<n;i++){
        if(s[i]==s[0]) dp[0][i]=1;
        ans=max(ans, dp[0][i]);
    }
    rep(i, n-1){
        for(int j=i+1;j<n-1;j++){
            //cout<<dp[i][j]<<" "<<i<<" "<<j<<endl;
            if(s[i+1]==s[j+1]) {
                dp[i+1][j+1]=dp[i][j]+1;
                if(j+1-dp[i+1][j+1]+1<=i+1){
                    dp[i+1][j+1]=1;
                }
            }
            else {
                dp[i+1][j+1]=0;
            }   
            ans=max(ans, dp[i+1][j+1]);
        }
    }
    cout<<ans<<endl;
    return 0;
}