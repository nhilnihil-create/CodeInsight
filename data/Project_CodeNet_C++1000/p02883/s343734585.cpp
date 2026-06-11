//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const ll INF=1e+18;
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
    ll N,K;
    cin>>N>>K;
    vector<ll> A(N);
    vector<ll> F(N);
    REP(i,N) cin>>A[i];
    REP(i,N) cin>>F[i];
    sort(A.begin(),A.end());
    sort(F.begin(),F.end(),greater<ll>());
    ll l,r,mid;
    l=-1;
    r=INF;
    while(r-l>1){
        mid=(l+r)/2;
        ll cnt=K;
        REP(i,N){
            if(A[i]>mid/F[i]){
                cnt-=(A[i]-mid/F[i]);
            }
        }
        if(cnt<0){
            l=mid;
        }else{
            r=mid;
        }
    }
    cout<<r<<endl;
}