#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>
#include <cstdint>



#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rrep(i, n) for(ll i = (ll)(n-1); i >= 0; i--)
#define repi(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rrepi(i,a,b) for(ll i=(ll)(b);i>=(ll)(a);i--)

#define all(x) (x).begin(),(x).end()

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;



class UnionFind
{
public:
  UnionFind(int n)
  {
    parent=vector<int>(n,-1);
  }
  int root(int a)
  {
    if(parent[a]<0)return a;
    return parent[a]=root(parent[a]);
  }
  int size(int a)
  {
    return -parent[root(a)];
  }
  bool connect(int a,int b)
  {
    int A=root(a);
    int B=root(b);
    if(A==B)return false;
    if(size(A)>size(B))swap(A,B);
    parent[B]+=parent[A];
    parent[A]=B;
    return true;
  }
private:
  vector<int> parent;

};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;cin>>n;
  vector<ll>x(n),y(n);
  rep(i,n)cin>>x[i]>>y[i];
  ll res=1e9;
  if(n==1){cout<<1<<endl;return 0;}
  rep(i,n)rep(j,n){
    if(i==j)continue;
    UnionFind uf(n);
    ll p=x[i]-x[j];
    ll q=y[i]-y[j];
    rep(k,n)rep(l,n){
      if(k==l)continue;
      ll tp=x[k]-x[l];
      ll tq=y[k]-y[l];
      if((tp==p&&tq==q)||(tp==-p&&tq==-q))uf.connect(k ,l);
    }
    set<ll>se;
    rep(k,n){
      se.insert(uf.root(k));
    }
    chmin(res,(ll)se.size());

  }
  cout<<res<<endl;


  return 0;

}
