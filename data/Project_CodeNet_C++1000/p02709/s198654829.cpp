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

// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

int main(){
    ll N;
    cin>>N;
    vector<pair<ll,ll>> A(N);
    REP(i,N){
        cin>>A[i].first;
        A[i].second=i;
    }

    sort(A.begin(),A.end(),greater<pair<ll,ll>>());

    vector<vector<ll>> dp(N+1,vector<ll>(N+1,0));
    REP(i,N){
        REP(j,N){
            ll a=A[i+j].first;
            ll idx=A[i+j].second;
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]+a*(idx-i));
            dp[i][j+1]=max(dp[i][j+1],dp[i][j]+a*(N-1-idx-j));
        }
    }

    ll ans=0;
    REP(i,N+1){
        ans=max(ans,dp[i][N-i]);
    }
    cout<<ans<<endl;
}