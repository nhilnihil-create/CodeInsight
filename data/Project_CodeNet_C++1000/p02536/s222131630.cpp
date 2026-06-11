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

struct unionfind{
  vector<int> par;
  vector<int> rank;
  unionfind(int n=1){
    init(n);
  }
  void init(int n=1){
      par.resize(n); rank.resize(n);
      for(int i=0;i<n;++i) par[i]=i,rank[i]=0;
  }
  int root(int x){
    if(par[x]==x){
      return x;
    }
    else{
      int r=root(par[x]);
      return par[x]=r;
    }
  }
  bool issame(int x,int y){
    return root(x)==root(y);
  }
  bool merge(int x,int y){
    x=root(x); y=root(y);
    if(x==y) return false;
    if(rank[x]<rank[y]) swap(x,y);
    if(rank[x]==rank[y]) ++rank[x];
    par[y]=x;
    return true;
  }
};

int main(){
  int n,m; cin >> n >> m;
  unionfind uf(n);
  rep(i,m){
    itn a,b;
    cin >> a >> b;
    a--; b--;
    uf.merge(a,b);
  }
  int ans=0;
  rep(i,n){
    if(!(uf.issame(0,i))){
      uf.merge(0,i);
      ans++;
    }
  }
  cout << ans << endl;
}