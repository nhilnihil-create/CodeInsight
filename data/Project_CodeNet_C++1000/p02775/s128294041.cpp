#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N=1e6+9;
ll dp[N][2],ls;
string s;
ll F(int i,int carry){
    if (i==ls)
        return carry;
    if (dp[i][carry]!=-1)
        return dp[i][carry];
    int val=s[i]-'0'+carry;
    ll mn=1e9;
    if (val<=9)
    mn=min(mn,F(i+1,0)+val);
    mn=min(mn,F(i+1,1)+10-val);
    return dp[i][carry]=mn;
}
int main()
{
    FASTINOUT;
    cin>>s;
    reverse(s.begin(),s.end());
    ls=s.length();
    memset(dp,-1,sizeof dp);
    cout<<F(0,0);
    return 0;
}
