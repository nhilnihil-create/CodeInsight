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

//省略
using vi  = vector<int>;
using vii = vector<vector<int>>;
using vl  = vector<ll>;
using vll = vector<vector<ll>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(){
    ll N;
    cin>>N;
    vl S(pow(2,N));
    REP(i,pow(2,N)) cin>>S[i];
    sort(ALL(S),greater<ll>());

    multiset<ll> st_no_used;
    multiset<ll,greater<ll>> st_used;

    st_used.insert(S[0]);
    REP2(i,1,pow(2,N)){
        st_no_used.insert(S[i]);
    }

    

    while(!st_no_used.empty()){
        vl input;
        for(auto itr=st_used.begin();itr!=st_used.end();itr++){
            ll x=*itr;
            auto itr2=st_no_used.lower_bound(x);
            if(itr2==st_no_used.begin()){
                cout<<"No"<<endl;
                return 0;
            }
            itr2--;
            input.emplace_back(*itr2);
            st_no_used.erase(itr2);
        }
        REP(i,input.size()){
            st_used.insert(input[i]);
        }
    }

    cout<<"Yes"<<endl;

}