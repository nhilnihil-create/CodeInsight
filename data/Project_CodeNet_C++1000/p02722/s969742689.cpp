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

vector<ll> enum_div(ll n){
    vector<ll> ret;
    for(ll i = 1 ; i*i <= n ; ++i){
        if(n%i == 0){
            ret.push_back(i);
            if(i != 1 && i*i != n){
                ret.push_back(n/i);
            }
        }
    }
    return ret;
}

int main(){
    ll N;
    cin>>N;
    vector<ll> K1=enum_div(N);;
    vector<ll> K2=enum_div(N-1);;
    K2.push_back(N-1);
    K2.push_back(N);
    set<ll> st;

    REP(i,K1.size()){
        if(K1[i]==1) continue;
        if(K1[i]==2){
            st.insert(2);
            continue;
        }
        ll k=K1[i];
        ll tmp=N;

        while(tmp>=k){
            if(tmp%k==0){
                tmp/=k;
            }else if(tmp%k==1){
                tmp=1;
                break;
            }else{
                break;
            }
        }
        if(tmp==1) st.insert(k);
    }


    REP(i,K2.size()){
        st.insert(K2[i]);
    }

    cout<<st.size()-1<<endl;
    

}