#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N=2e6+5;
string s;
int dp[N][2];
int solve(int idx,int c)
{
    if(idx<0) return c;
    int &ret=dp[idx][c];
    if(~ret) return ret;
    int cur=s[idx]-'0'+c;
    ret=solve(idx-1,0)+cur;
    ret=min(ret,solve(idx-1,1)+10-cur);
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s;
    memset(dp,-1,sizeof dp);
    cout<<solve((int)s.size()-1,0)<<endl;
    return 0;
}
