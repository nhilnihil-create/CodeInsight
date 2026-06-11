#include<bits/stdc++.h>
#include<string.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define see(x) cout<<#x<<" : "<<(x)<<endl;
#define ya cout<<"yes"<<endl;
#define no cout<<"no"<<endl;
#define ff first
#define sc second
typedef unsigned long long ll;
using namespace std;
ll dp[100009][15];
const ll mod=1e9+7;
int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(NULL),cout.tie(NULL);
    ll n,k,ans=0,i,j;
    string s;
    cin>>s;
    n=s.size();
    if(s[0]=='?')
    {
        for(i=0;i<=9;i++)
        {
            dp[0][i]=1;
        }
    }
    else
    {
        dp[0][s[0]-'0']=1;
    }
    for(i=1;i<n;i++)
    {
        if(s[i]=='?')
        {
            for(j=0;j<=12;j++)
            {
                for(k=0;k<=9;k++)
                {
                    dp[i][(j*10+k)%13]=(dp[i][(j*10+k)%13]%mod + dp[i-1][j]%mod)%mod;
                }
            }
        }
        else
        {
            for(j=0;j<=12;j++)
            {
                ll x=s[i]-'0';
                dp[i][(j*10+x)%13]=(dp[i][(j*10+x)%13]%mod+ dp[i-1][j]%mod)%mod;
            }
        }
    }
//    for(i=0;i<n;i++)
//    {
//        for(j=0;j<=12;j++)
//        {
//            cout<<dp[i][j]<<' ';
//        }
//        cout<<endl;
//    }
    cout<< dp[n-1][5] <<endl;
    return 0;
}
