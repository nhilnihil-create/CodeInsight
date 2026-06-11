#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;

ll dp[100010][2];
const ll MOD=1e9+7;

int main(){
    string s;
    cin>>s;
    ll n=s.size();
    dp[0][0]=1;
    rep(i,0,n){
        if(s[i]=='0'){
            dp[i+1][0]=dp[i][0];
            dp[i+1][1]=3*dp[i][1];
            dp[i+1][0]%=MOD;
            dp[i+1][1]%=MOD;
        }
        else{
            dp[i+1][0]=dp[i][0]*2;
            dp[i+1][1]=3*dp[i][1];
            dp[i+1][1]+=dp[i][0];
            dp[i+1][0]%=MOD;
            dp[i+1][1]%=MOD;
        }
    }
    ll an=dp[n][0]+dp[n][1];
    an%=MOD;
    cout<<an<<endl;
}

    







