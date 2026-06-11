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
    cin>>N;
    vector<ll> P(N);
    vector<pair<ll,ll>> P_sorted(N);
    REP(i,N){
        cin>>P[i];
        P_sorted[i]=make_pair(P[i],i);
    }

    sort(P_sorted.begin(),P_sorted.end());
    ll ans=0;

    multiset<ll> st;
    st.insert(-1);
    st.insert(-1);
    st.insert(N);
    st.insert(N);

    REPD2(i,N-1,-1){
        ll num=P_sorted[i].first;
        ll idx=P_sorted[i].second;
        st.insert(idx);

        auto itr_r=st.find(idx);
        auto itr_l=st.find(idx);
        itr_r++;
        ll r2=*itr_r;
        itr_r++;
        ll r1=*itr_r;

        itr_l--;
        ll l2=*itr_l;
        itr_l--;
        ll l1=*itr_l;

        ans+=((l2-l1)*(r2-idx)+(r1-r2)*(idx-l2))*num;
        
    }
    cout<<ans<<endl;
}