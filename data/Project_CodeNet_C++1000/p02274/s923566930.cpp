#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<iomanip>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

const int MAX = 510000;
const int MOD = 1000000007;

//1-indexed
class BIT {
public:
    ll n; //データの長さ
    vector<ll> bit; //データの格納先
    BIT(ll n):n(n),bit(n+1,0){} //コンストラクタ

    //k & -kはLSB

    //bit_iにxをO(log(n))で加算する
    void add(ll i,ll x){
        if(i==0) return;
        for(ll k=i;k<=n;k+=(k & -k)){
            bit[k]+=x;
        }
    }

    //bit_1 + bit_2 + …  + bit_n をO(log(n))で求める
    ll sum(ll i){
        ll s=0;
        if(i==0) return s;
        for(ll k=i;k>0;k-=(k & -k)){
            s+=bit[k];
        }
        return s;
    }

    //a_1 + a_2 + … + a_i >= x となるような最小のiを求める(a_k >= 0)
    //xが0以下の場合は該当するものなし→0を返す
    ll lower_bound(ll x){
        if(x<=0){
            return 0;
        }else{
            ll i=0;ll r=1;
            //最大としてありうる区間の長さを取得する
            //n以下の最小の二乗のべき(BITで管理する数列の区間で最大のもの)を求める
            while(r<n) r=r<<1;
            //区間の長さは調べるごとに半分になる
            for(int len=r;len>0;len=len>>1) {
                //その区間を採用する場合
                if(i+len<n && bit[i+len]<x){
                    x-=bit[i+len];
                    i+=len;
                }
            }
            return i+1;
        }
    }
};

template< typename T >
struct Compress {
  vector< T > xs;

  Compress() = default;

  Compress(const vector< T > &vs) {
    add(vs);
  }

  Compress(const initializer_list< vector< T > > &vs) {
    for(auto &p : vs) add(p);
  }

  void add(const vector< T > &vs) {
    copy(begin(vs), end(vs), back_inserter(xs));
  }

  void add(const T &x) {
    xs.emplace_back(x);
  }

  void build() {
    sort(begin(xs), end(xs));
    xs.erase(unique(begin(xs), end(xs)), end(xs));
  }

  vector< int > get(const vector< T > &vs) const {
    vector< int > ret;
    transform(begin(vs), end(vs), back_inserter(ret), [&](const T &x) {
      return lower_bound(begin(xs), end(xs), x) - begin(xs);
    });
    return ret;
  }

  int get(const T &x) const {
    return lower_bound(begin(xs), end(xs), x) - begin(xs);
  }

  const T &operator[](int k) const {
    return xs[k];
  }
};


int main(){
  ll N; cin >> N;
  vector<ll> a(N); rep(i,N) cin >> a[i];
  Compress<ll> comp(a);
  comp.build();
  vector<ll> b;
  for(auto &p : comp.get(a)) b.pb(p + 1);

  BIT bit(N);
  ll ans = 0;
  rep(i,N){
    ans += i - bit.sum(b[i]);
    bit.add(b[i] , 1);
  }
  cout << ans << endl;
}

