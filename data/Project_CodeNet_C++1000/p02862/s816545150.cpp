#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define eb emplace_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
#define fi first
#define se second
#define pi M_PI
#define PQ(T) priority_queue<T>
#define SPQ(T) priority_queue<T,vector<T>,greater<T>>
using ll=long long;
using P=pair<ll,ll>;
using PP=tuple<ll,ll,ll>;
using S=multiset<ll>;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
const ll inf=1001001001001001;
const int INF=1001001001;
const int mod=1000000007;
const double eps=1e-10;
template<class T> bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> void outp(T a){cout<<'('<<a.fi<<','<<a.se<<')'<<'\n';}
template<class T> void outvp(T v){rep(i,v.size())cout<<'('<<v[i].fi<<','<<v[i].se<<')';cout<<'\n';}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<'\n';}
template<class T> void outvv(T v){rep(i,v.size())outv(v[i]);}
template<class T> bool isin(T x,T l,T r){return (l)<=(x)&&(x)<=(r);}
template<class T> void YesNo(T b){if(b)out("Yes");else out("No");}
void decimal(int x){cout<<fixed<<setprecision(x);}
ll GCD(ll a,ll b){if(b==0) return a; return GCD(b,a%b);}
ll LCM(ll a,ll b){return(a/GCD(a,b))*(b/GCD(a,b))*GCD(a,b);}
ll POW(ll a,ll b){a%=mod;if(b==0)return 1;if(b&1)return a*POW(a,b-1)%mod;ll k=POW(a,b/2);return k*k%mod;}
vi calc(ll x){vi res;while(x>0){res.eb(x%10);x/=10;}reverse(all(res));return res;}

const ll max_n=670000;
vi fac(max_n),finv(max_n),inv(max_n);
// テーブルを作る前処理 O(max_n)
void init(){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  REP(i,2,max_n){
    fac[i]=fac[i-1]*i%mod;
    inv[i]=mod-inv[mod%i]*(mod/i)%mod;
    finv[i]=finv[i-1]*inv[i]%mod;
  }
}
// 二項係数計算 O(1)
ll COM(int n,int k){
  if(n<k) return 0;
  if(n<0||k<0) return 0;
  return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}
//init(); を忘れない！
void solve() {
  init();
  ll x,y;
  cin>>x>>y;
  if((x+y)%3){
    out(0); return;
  }
  ll p=(x+y)/3;
  x-=p; y-=p;
  if(x<0||y<0){
    out(0); return;
  }
  if(x>y) swap(x,y);
  out(COM(x+y,x));
  //cout<<x<<" "<<y<<'\n';
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}
