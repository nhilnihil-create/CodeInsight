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
    ll T1,T2,A1,A2,B1,B2;
    cin>>T1>>T2;
    cin>>A1>>A2;
    cin>>B1>>B2;
    if(A1*T1+A2*T2==B1*T1+B2*T2){
        cout<<"infinity"<<endl;
    }else{
        ll ans=0;
        if(A1<B1){
            swap(A1,B1);
            swap(A2,B2);
        }
        ll dis=-(T1*(A1-B1)+T2*(A2-B2));
        if(dis<0){
            ans=0;
        }else{
            ll cnt=T1*(A1-B1)/dis;
            
            ans=(cnt)*2+1;
            if((T1*(A1-B1))%dis==0) ans--;
            
        }

        cout<<ans<<endl;
    }

}