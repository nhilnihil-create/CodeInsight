#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007 
#define ff first
#define ss second
typedef long long ll;
ll power(ll a, ll b){//a^b
    ll res=1;
    a=a%MOD;
    while(b>0){
        if(b&1){res=(res*a)%MOD;b--;}
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
ll fermat_inv(ll y){return power(y,MOD-2);}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s[n];
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        vector <vector<int>> dp(n,vector<int> (m,n+m+10));
        if(s[0][0]=='.')
            dp[0][0]=0;
        else
            dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j-1>=0&&s[i][j]=='#'&&s[i][j-1]=='.')
                    dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                else if(j-1>=0)
                    dp[i][j]=min(dp[i][j],dp[i][j-1]);
                if(i-1>=0&&s[i][j]=='#'&&s[i-1][j]=='.')
                    dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
                else if(i-1>=0)
                    dp[i][j]=min(dp[i][j],dp[i-1][j]);
            }
        }
        cout<<dp[n-1][m-1]<<"\n";
    }
    return 0;
}