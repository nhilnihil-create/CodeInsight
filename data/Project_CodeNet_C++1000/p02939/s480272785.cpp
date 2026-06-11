#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int dp[200009][4], n;
string s ;
int solve(int i, int last)
{
    if(i>n)
        return -2*n;
    if(i==n)
        return 0 ;
    int &ans=dp[i][last];
    if(ans!=-1)
        return ans;
    ans=0;
    if(last==0)
        ans=1+max(solve(i+1,1),solve(i+2,2));
    else if(last==1)
    {
        if(s[i]!=s[i-1])
            ans=1+solve(i+1,1);
        ans=max(ans,1+solve(i+2,2));
    }
    else if(last==2)
    {
        ans=1+solve(i+1,1);
        if(s[i]!=s[i-2] && s[i+1]!=s[i-1])
            ans=max(ans,1+solve(i+2,2));
    }
    return ans;
}
int main()
{
    IO
    cin>>s;
    n=s.size();
    s+='*';
    memset(dp,-1,sizeof dp);
    cout<<solve(0,0);
}
