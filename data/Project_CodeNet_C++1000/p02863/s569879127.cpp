//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const int INF=1e+9;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>(ll)(b);i--)

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

//グローバル変数


//ライブラリ挿入


int main(){
    ll N,T;
    cin>>N>>T;
    vector<pair<ll,ll>> AB(N);
    REP(i,N) cin>>AB[i].first>>AB[i].second;
    sort(AB.begin(),AB.end());
    vector<vector<ll>> dp(3010,vector<ll>(6010,0));
    REP(i,N){
        REP(j,6010){
            if(j-AB[i].first>=0&&j-AB[i].first<T) dp[i+1][j]=max(dp[i][j-AB[i].first]+AB[i].second,dp[i][j]);
            else dp[i+1][j]=dp[i][j];
        }
    }
    ll ans=0;
    REP(j,6010){
        ans=max(ans,dp[N][j]);
    }
    cout<<ans<<endl;
    
}