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
    ll N,P;
    cin>>N>>P;
    string tmp;
    cin>>tmp;

    vector<ll> S(N);
    REP(i,N){
        S[i]=tmp[i]-'0';
    }
    vector<ll> U(N+1,0);
    map<ll,ll> mp;
    mp[0]++;
    ll ans=0;
    if(P==2||P==5){
        REP(i,N){
            if(S[i]%P==0) ans+=(i+1);
        }
    }else{
        REP(i,N){
            U[N-1-i]=(U[N-i]+mod_pow(10,i,P)*S[N-1-i])%P;
            if(mp.count(U[N-i-1])){
                ans+=mp[U[N-1-i]];
            }
            mp[U[N-1-i]]++;
        }
    }
    
    cout<<ans<<endl;
}