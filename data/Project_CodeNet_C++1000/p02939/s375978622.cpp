#include "bits/stdc++.h"
using namespace std;
#define all(v) (v).begin(), (v).end()
#define io ios::sync_with_stdio(0)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rson rt << 1 | 1, mid + 1, r
#define lson rt << 1, l, mid
#define lll __int128
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eps 1e-12
#define int long long
const int mod = 1e9 + 7;
inline int ksm(int a, int b)
{
    int ans = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1)
            ans = ans * a % mod;
    return ans;
}
int dp[300000][4];
char s[300000];
void upd(int &x,int y){
    if(x<y)x=y;
}
signed main()
{
    io;
    cin>>s+1; int n=strlen(s+1);
    //dp[0][10]=1;
    for(int i=1;i<=n;i++){
        rep(j,1,3){
            rep(k,1,3){
                if(i-j>=0 && j!=k){
                   // cout<<i<<" "<<j<<" "<<k<<endl;
                  //  cout<<dp[i][j]<<" "<<dp[i-j][k]<<endl;
                    upd(dp[i][j],dp[i-j][k]+1);
                }
            }
        }
        rep(j,1,3){
          //  cout<<dp[i][j]<<" ";
          if(i-j-j>=0){
              string a="",b="";
              for(int k=i-j-j+1;k<=i;k++){
                  if(k<=i-j)a+=s[k];
                  else b+=s[k];
              }
              if(a!=b)upd(dp[i][j],dp[i-j][j]+1);
          }
        }
      //  cout<<endl;
    }
    int ans=1;
    rep(i,1,3)upd(ans,dp[n][i]);
    cout<<ans<<endl;
    getchar(); //0
    getchar();
}
