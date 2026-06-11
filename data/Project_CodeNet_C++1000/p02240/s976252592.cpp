#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define erep(i,a,b) for(int i=a;i<=(int)(b);++i)
#define per(i,a,b) for(int i=(b);i>(a);--i)
#define eper(i,a,b) for(int i=((int)(a));i>=b;--i)
#define pb push_back
#define mp make_pair
#define INF 2000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a, b)*b;}

template <typename T> class union_find {
  vector<T> par, rank;

public:
  union_find(size_t n) {
    par.reserve(n + 1);
    rank.reserve(n + 1);
  }

public:
  void init(T n) { // add a set
    rep(i, 0, n) {
      par[i] = i;
      rank[i] = 0;
    }
  }

public:
  T find(T x) { // find the parent of x
    if (par[x] == x)
      return x;
    else
      return par[x] = find(par[x]);
  }

public:
  void unite(T x, T y) { // unite x and y
    x = find(x);
    y = find(y);
    if (x == y)
      return;
    if (rank[x] < rank[y])
      par[x] = y;
    else
      par[y] = x;
    if (rank[x] == rank[y])
      rank[x]++;
  }

public:
  bool same(T x, T y) { // compare x's parent and y's parent
    return find(x) == find(y);
  }
};

int n, m;
vector<int> s, t;
int q;  
int main() {
 ios::sync_with_stdio ( false );
 cin.tie ( 0 );
    cin >> n >> m;
    union_find<int> uf = union_find<int>(n+1);
    uf.init(n);
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        s.pb(a); t.pb(b);
        uf.unite(a, b);
    }
    cin >> q;
    rep(i, 0, q) {
        int k, l; cin >> k >> l;
        if (uf.same(k, l)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
