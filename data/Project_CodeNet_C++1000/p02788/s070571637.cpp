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
    int N;
    ll D,A;
    cin>>N>>D>>A;
    vector<pair<ll,ll>> XI(N);
    vector<ll> X(N);
    vector<ll> H_tmp(N),H(N);
    REP(i,N){
        cin>>XI[i].first>>H_tmp[i];
        XI[i].second=i;
        H_tmp[i]=(H_tmp[i]+A-1)/A;
    }
    sort(ALL(XI));
    REP(i,N){
        int idx=XI[i].second;
        X[i]=XI[i].first;
        H[i]=H_tmp[idx];
    }

    vector<ll> S(N+1,0);
    ll ans=0;
    REP(i,N){
        ll x=X[i];
        ll h=H[i]-S[i];
        if(S[i] < H[i]){
            int id=upper_bound(ALL(X),x+2*D)-X.begin();
            S[i]+=h;
            if(id!=N) S[id]-=h;
            ans+=h;
        }
        S[i+1]+=S[i];
    }
    cout<<ans<<endl;

}