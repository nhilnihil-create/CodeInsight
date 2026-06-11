#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
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

struct UnionFind{
	vi d;
	UnionFind(ll n=0):d(n,-1){}
	ll find(ll x){
		if(d[x]<0) return x;
		return d[x]=find(d[x]);
	}
	bool unite(ll x,ll y){
		x=find(x); y=find(y);
		if(x==y) return false;
		if(d[x]>d[y]) swap(x,y);
		d[x]+=d[y];
		d[y]=x;
		return true;
	}
	bool same(ll x,ll y){return find(x)==find(y);}
	ll size(ll x){return -d[find(x)];}
};

void solve(){
  int n,q;
  cin>>n>>q;
  UnionFind uf(n);
  rep(i,q){
  	int k,u,v;
  	cin>>k>>u>>v;
  	if(k==0) uf.unite(u,v);
  	else out(uf.same(u,v));
  }
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}
