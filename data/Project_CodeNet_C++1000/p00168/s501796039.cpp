#include<iostream>
using namespace std;
long dp[31];
main()
{
    dp[0]=1;
    for(int i=1;i<=30;i++)
    {
        for(int j=1;j<=3&&i-j>=0;j++)dp[i]+=dp[i-j];
    }
    int n;
    while(cin>>n,n)cout<<(dp[n]-1)/3650+1<<endl;
}
