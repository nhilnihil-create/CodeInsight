#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=3.141592653589793;
const ll MOD=1e9+7;

int main() {
    int n,m;
    cin>>n>>m;
    int s[n+1],t[m+1];
    rep(i,n){
        cin>>s[i+1];
    }
    rep(i,m){
        cin>>t[i+1];
    }
    ll dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for (int i=0;i<n+1;i++){
        for (int j=0;j<m+1;j++){
            if (i==0 || j==0){
                dp[i][j]=1;
            }
            else{
                if (s[i]==t[j]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-2*dp[i-1][j-1];
                }
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
                }
                dp[i][j]=(dp[i][j]+MOD)%MOD;
            }
        }
    }
    cout<<dp[n][m]<<endl;

    return 0;
}
