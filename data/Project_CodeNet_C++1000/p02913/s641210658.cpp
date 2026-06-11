#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int dp[n+1][n+1]={};
    for(int i=n-1;i>=0;i--)for(int j=n-1;j>=0;j--)if(s[i]==s[j])dp[i][j]=dp[i+1][j+1]+1;
    int x=0;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)x=max(x,min(dp[i][j],abs(i-j)));
    cout<<x<<endl;
    return 0;
}
