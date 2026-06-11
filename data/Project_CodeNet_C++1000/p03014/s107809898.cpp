#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp1[2010][2010];
ll dp2[2010][2010];
ll dp3[2010][2010];
ll dp4[2010][2010];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll h,w;
    cin>>h>>w;
    vector<string>s;
    string s1;
    for(ll i=0;i<h;i++)
    {
        cin>>s1;
        s.push_back(s1);
    }
    for(ll i=1;i<=h;i++)
    {
        for(ll j=1;j<=w;j++)
        {
            if(s[i-1][j-1]=='#')
                dp1[i][j]=0;
            else
                dp1[i][j]=dp1[i][j-1]+1;
        }
        for(ll j=w;j>=1;j--)
        {
            if(s[i-1][j-1]=='#')
                dp2[i][j]=0;
            else
                dp2[i][j]=dp2[i][j+1]+1;
        }
    }
    for(ll j=1;j<=w;j++)
    {
        for(ll i=1;i<=h;i++)
        {
            if(s[i-1][j-1]=='#')
                dp3[i][j]=0;
            else
                dp3[i][j]=dp3[i-1][j]+1;
        }
        for(ll i=h;i>=1;i--)
        {
            if(s[i-1][j-1]=='#')
                dp4[i][j]=0;
            else
                dp4[i][j]=dp4[i+1][j]+1;
        }
    }
    ll maxi=0;
    for(ll i=1;i<=h;i++)
    {
        for(ll j=1;j<=w;j++)
        {
            maxi=max(maxi,dp1[i][j]+dp2[i][j]+dp3[i][j]+dp4[i][j]-3);
        }
    }
    cout<<maxi;
}																		