//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const ll INF=1e+10;
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
    ll N,M,V,P;
    cin>>N>>M>>V>>P;
    vector<ll> A(N);
    vector<ll> A_sort(N);
    REP(i,N){
        cin>>A[i];
        A_sort[i]=A[i];
    }
    sort(ALL(A_sort));
    vector<ll> s(N+1,0);
    REP(i,N){
        s[i+1]=s[i]+A_sort[i];
    }

    ll l=-1;
    ll r=INF;
    while(r-l>1){
        ll x=(l+r)/2;
        bool ok=true;
        int num=upper_bound(ALL(A_sort),x+M)-A_sort.begin();
        int over=N-num;
        if(over>=P) ok=false;

        ll nokori=(V-P)*M;

        REP(i,N-P){
            ll cnt=min(M,x+M-A_sort[i]);
            nokori-=cnt;
        }

        if(x<=A_sort[N-P-1]){
            nokori+=M;
            nokori-=min(M,x+M-A_sort[N-P]);
        }

        if(nokori>0) ok=false;
        if(ok){
            r=x;
        }else{
            l=x;
        }
    }

    int ans=A_sort.end()-upper_bound(ALL(A_sort),l);
    cout<<ans<<endl;


}