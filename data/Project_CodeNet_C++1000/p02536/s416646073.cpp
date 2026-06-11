#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define EPS (1e-10)
#define equals(a, b) (fabs((a)-(b)) < EPS)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef set<int> S;
typedef queue<int> Q;
typedef queue<P> QP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 1000000007;

class UnionFind {
  public:
    vi Parent;
    UnionFind(int N) {
      Parent = vi(N,-1);
    }
  
    int root(int A) {
      if(Parent[A] < 0) return A;
      return Parent[A] = root(Parent[A]);
    }
  
    int size(int A) {
      return -Parent[root(A)];
    }
  
    bool connect(int A,int B) {
      A = root(A);
      B = root(B);
      if(A == B) return false;
      if(size(A) < size(B)) swap(A,B);
      Parent[A] += Parent[B];
      Parent[B] = A;
      return true;
    }
};
  
int main() {
  int n,m;
  cin >> n >> m;
  UnionFind uf(n);
  rep(i,m) {
    int a,b;
    cin >> a >> b;
    a--;b--;
    uf.connect(a,b);
  }
  map<int,int> mp;
  rep(i,n) {
    mp[uf.root(i)]++;
  }
  cout << sz(mp)-1 << endl;
  return 0;
}