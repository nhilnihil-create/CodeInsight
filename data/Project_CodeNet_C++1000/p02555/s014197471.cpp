#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned int ui;
#define infin (ll)(pow(10,9)+7)
using namespace std;
int main()
{
    int s;
    cin>>s;
    ll dp[s+1];
    dp[0]=1;
    dp[1]=0;
    dp[2]=0;
    for(int i=3;i<=s;i++)
    {
        dp[i]=(dp[i-1]+dp[i-3])%infin;
    }
    cout<<dp[s]<<endl;
}
