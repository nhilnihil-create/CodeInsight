#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define print(x)cout<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;

ll dp[1010][1<<13];
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
const ll inf = 1LL<<60;
int main() {
  int n,m;
  cin >> n >> m;
  vi a(m),c(m);
  Fill(dp,inf);
  rep(i,m){
    int b;
    cin >> a[i] >> b;
    int key=0;
    rep(j,b){
      int tmp;
      cin >> tmp;
      key|=(1<<(tmp-1));
    }
    c[i] = key;
  }
  dp[0][0] = 0;
  rep(i,m){
    rep(j,(1<<n)){
      mins(dp[i+1][j],dp[i][j]);
      dp[i][j|c[i]] = min(dp[i][j|c[i]],dp[i][j]+a[i]);
    }
  }
  cout<<((dp[m][(1<<n)-1] == inf)?-1:dp[m][(1<<n)-1])<<endl;
  return 0;
}