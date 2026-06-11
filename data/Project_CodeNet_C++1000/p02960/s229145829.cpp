#include <bits/stdc++.h>
#define ll  long long int
#define mod 1000000007
using namespace std;
int main() {
    string s;
    cin>>s;
    ll n=s.length();
    ll dp[n+1][13];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(ll i=1;i<n+1;i++){
        ll nxt=s[i-1]-'0';
            for(ll j=0;j<=9;j++){
                if(s[i-1]=='?')nxt=j;
                for(ll k=0;k<13;k++){
                    ll rem=(10*k+nxt)%13;
                dp[i][rem]+=dp[i-1][k];
                    dp[i][rem]%=mod;}
                if(s[i-1]!='?')break;
            }
        
    }
    cout<<dp[n][5]<<"\n";
}


