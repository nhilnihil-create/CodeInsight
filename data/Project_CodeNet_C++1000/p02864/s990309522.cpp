#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll; const int inf = 0x3fffffff; const ll INF = 0x3fffffffffffffff;
template<class T> inline bool chmax(T& a,T b){ if(a<b){a=b;return 1;}return 0; }
template<class T> inline bool chmin(T& a,T b){ if(a>b){a=b;return 1;}return 0; }
//template end

ll dp[310][310];

int main(){
    int n,k; scanf("%d%d",&n,&k);
    vector<int> a(n+1,0);
    rep(i,1,n+1)scanf("%d",&a[i]);
    rep(i,0,310)rep(j,0,310)dp[i][j]=INF;
    dp[0][0]=0;
    rep(i,0,n+1)rep(j,0,n+1){
        ll sub=INF;
        rep(rot,0,i)chmin(sub,dp[rot][j]+max(0,a[i]-a[rot]));
        chmin(dp[i][j+1],sub);
    }
    ll ans=INF;
    rep(i,0,n+1)chmin(ans,dp[i][n-k]);
    printf("%lld\n",ans);
    return 0;
}