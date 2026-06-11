//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const ll INF=1e+14;
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

template <class Abel> struct BIT {
    vector<Abel> dat[2];
    Abel UNITY_SUM = 0;                     // to be set
    
    /* [1, n] */
    BIT(int n) { init(n); }
    void init(int n) { for (int iter = 0; iter < 2; ++iter) dat[iter].assign(n + 1, UNITY_SUM); }
    
    /* a, b are 1-indexed, [a, b) */
    inline void sub_add(int p, int a, Abel x) {
        for (int i = a; i < (int)dat[p].size(); i += i & -i)
            dat[p][i] = dat[p][i] + x;
    }
    inline void add(int a, int b, Abel x) {
        sub_add(0, a, x * -(a - 1)); sub_add(1, a, x); sub_add(0, b, x * (b - 1)); sub_add(1, b, x * (-1));
    }
    
    /* a is 1-indexed, [a, b) */
    inline Abel sub_sum(int p, int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i) res = res + dat[p][i];
        return res;
    }
    inline Abel sum(int a, int b) {
        return sub_sum(0, b - 1) + sub_sum(1, b - 1) * (b - 1) - sub_sum(0, a - 1) - sub_sum(1, a - 1) * (a - 1);
    }
    
    /* debug */
    void print() {
        for (int i = 1; i < (int)dat[0].size(); ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};


int main(){
    ll N,D,A;
    cin>>N>>D>>A;
    vector<pair<ll,ll>> XH(N+1);
    vector<ll> L(N+1);
    BIT<ll> bit(N+10);
    XH[0]=make_pair(-INF,0);
    REP(i,N){
        ll x,h;
        cin>>x>>h;
        x-=D;
        if(h%A!=0){
            h=h/A+1;
        }else{
            h=h/A;
        }
        
        XH[i+1]=make_pair(x,h);
    }
    sort(ALL(XH));
    REP2(i,1,N+1){
        bit.add(i,i+1,XH[i].second);
        L[i]=XH[i].first;
    }
    L[0]=-INF;
    ll cnt=0;
    REP2(i,1,N+1){
        if(bit.sum(i,i+1)<=0) continue;
        ll down=bit.sum(i,i+1);
        cnt+=down;
        int l=i;
        int r=upper_bound(ALL(L),L[i]+2*D)-L.begin();
        bit.add(l,r,-down);
    }
    cout<<cnt<<endl;


    
}