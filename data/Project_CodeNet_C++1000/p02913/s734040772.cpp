#include<iostream>
using namespace std;
int n,dp[5001][5001];
string s;
int main(){
    cin>>n>>s;
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(s[i]!=s[j])dp[i][j]=0;
            else dp[i][j]=dp[i+1][j+1]+1;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        if(i>=j)continue;
        ans=max(ans,min(dp[i][j],j-i));
    }
    cout<<ans<<endl;
    return 0;
}