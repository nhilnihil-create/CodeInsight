#include <bits/stdc++.h>
using namespace std;
int main()
{
    int dp[9];
    int n,a,F =0;
    for(int i=0; i<9; i++) cin>>dp[i];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        for(int j=0; j<9; j++)
            if(dp[j]==a) dp[j]=0;
    }
    if(dp[0]==0&&dp[4]==0&&dp[8]==0) F=1;
    else if(dp[2]==0&&dp[4]==0&&dp[6]==0)F=1;
    for(int i=0; i<3; i++)
        if(dp[i]==0&&dp[i+3]==0&&dp[i+6]==0) F=1;
    for(int i=0; i<7; i+=3)
        if(dp[i]==0&&dp[i+1]==0&&dp[i+2]==0) F=1;
    F?cout<<"Yes"<<endl:cout<<"No"<<endl;
}
