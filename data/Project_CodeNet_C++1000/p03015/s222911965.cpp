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
// xのn乗%modを計算
ll mod_pow(ll x, ll n, ll mod){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res*x%mod;
        x = x*x%mod;
        n >>= 1;
    }
    return res;
}

int main(){
    string L;
    cin>>L;
    int N=L.size();
    auto dp=make_vec<ll>(N+1,2);
    dp[0][0]=1;
    dp[0][1]=0;
    REP(i,N){
        int L_i=L[i]-'0';
        REP(j,2){
            REP(k,j ? 2 : (L_i+1)){
                dp[i+1][j||k<L_i]+=(dp[i][j]*(k+1));
                dp[i+1][j||k<L_i]%=MOD;
            }
        }
    }
    cout<<((dp[N][0]+dp[N][1])%MOD)<<endl;
}