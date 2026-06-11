#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define pb push_back
typedef vector<int> vi;
#define mod 1000000007
#define maxn 100005
#define nos ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int dp[maxn][13];      //here dp[i][j] represents that we got j as remainder upto ith index starting from end
int power(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)
        res=(res*x)%13;
        x=(x*x)%13;
        y/=2;
    }
    return res;
}
int32_t main() {
    nos;
    string s;
    memset(dp,0,sizeof(dp));
    cin>>s;
    int n=s.size();
    if(s[n-1]=='?')
    {for(int i=0;i<10;i++)
     dp[n][i]++;
    }
    else
    dp[n][s[n-1]-'0']++;
    
    int c=1;
    for(int i=n-1;i>=1;i--)
    {   if(s[i-1]=='?')
        {
            for(int j=0;j<10;j++)        //we can try all 10 digits on ?
            {   
                for(int k=0;k<13;k++)
                    {   if(dp[i+1][k]!=0)
                        dp[i][(k+j*power(10,c))%13]=(dp[i][(k+j*power(10,c))%13]+dp[i+1][k])%mod;
                    }
            }
        }
        else
        {int j=s[i-1]-'0';               //while we have only one digit at fixed place
          for(int k=0;k<13;k++)
            {  
                if(dp[i+1][k]!=0)
                {
                        dp[i][(k+j*power(10,c))%13]=(dp[i][(k+j*power(10,c))%13]+dp[i+1][k])%mod;
                }
            }
        }
      c++;  
    }
    cout<<dp[1][5];
    return 0;
}
