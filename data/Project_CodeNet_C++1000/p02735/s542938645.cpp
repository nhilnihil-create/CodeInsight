#include "bits/stdc++.h"
using namespace std;
#define all(v) (v).begin(), (v).end()
#define io ios::sync_with_stdio(0)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rson rt << 1 | 1, mid + 1, r
#define lson rt << 1, l, mid
#define lll __int128
//#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eps 1e-12
const int mod = 1e9 + 7;
inline int ksm(int a, int b)
{
    int ans = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1)
            ans = ans * a % mod;
    return ans;
}

char a[500][500];
int dp[500][500];
int n,m;
void upd(int &x,int y){
    if(x>y)x=y;
}
signed main(){
   
    cin>>n>>m;
    rep(i,1,n)rep(j,1,m)cin>>a[i][j];
    memset(dp,0x3f,sizeof dp);
    dp[0][1]=0;
    rep(i,1,n){
        rep(j,1,m){
            if(a[i][j]=='#'){
                upd(dp[i][j],dp[i-1][j] + 1 - (a[i-1][j] == '#'));
                upd(dp[i][j],dp[i][j-1] + 1 - (a[i][j-1] == '#'));
            }
            else {
                upd(dp[i][j],dp[i-1][j]);
                upd(dp[i][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m]<<endl;


    getchar();getchar();

}
