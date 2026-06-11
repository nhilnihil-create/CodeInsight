#ifdef __LOCAL
  #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b) {if(a<b) {a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b) {if(a>b) {a=b; return true;} return false;}
#define itn int
#define fi first
#define se second
#define intmax numeric_limits<int>::max()
#define llmax numeric_limits<ll>::max()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>=1;i--)
#define all(vec) vec.begin(),vec.end()
#define sortt(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend())
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;
const ll lnf=1ll<<60;

template<typename T>
struct BIT{
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1){}
  void add(int i,T x=1) {
    for(i++;i<=n;i+= i&-i){
      d[i]+=x;
    }
  }
  T sum(int i){
    T x=0;
    for(i++;i;i-= i&-i){
      x+=d[i];
    }
    return x;
  }
  T sum(int l,int r){  //l~r-1のΣ
    return sum(r-1)-sum(l-1);
  }
  ll tentousuu(vector<T> a){  //aの値を0から始める
    ll ans=0;
    for(int j=0;j<n;j++){
      ans+=j-sum(a[j]);
      add(a[j],1);
    }
    return ans;
  }
};

int main(){
  itn n,q; cin >> n >> q;
  BIT<ll> bit(n);
  rep(i,n){
    itn a; cin >> a;
    bit.add(i,a);
  }
  vector<ll> ans(0);
  rep(i,q){
    itn t,u,v;
    cin >> t >> u >> v;
    if(t==0) bit.add(u,v);
    else ans.push_back(bit.sum(u,v));
  }
  rep(i,ans.size()){
    cout << ans[i] << endl;
  }
  
}