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
typedef vector<double> vd;
typedef pair<double,double> PD;
typedef pair<int,P> ed;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 1000000007;

int N;
int id[1010][1010];
vvi A,G;

int getId(int i,int j) {
  if(i>j) {
    swap(i,j);
  }
  return id[i][j];
}
bool visited[501000];
bool calced[501000];
int dp[501000];

int dfs(int k) {
  if(visited[k]) {
    if(!calced[k]) return -1;
    return dp[k];
  }
  visited[k] = true;
  dp[k] = 1;
  rep(i,sz(G[k])) {
    int t = G[k][i];
    int res = dfs(t);
    if(res==-1) return -1;
    chmax(dp[k],res+1);
  }
  calced[k] = true;
  return dp[k];
}
  
int main() {
  cin >> N;
  A = vvi(N,vi(N-1));
  rep(i,N) {
    rep(j,N-1) {
      cin >> A[i][j];
      A[i][j]--;
    }
  }
  int c=0;
  rep(i,N) {
    rep(j,N) {
      if(i<j) {
        id[i][j] = c;
        c++;
      }
    }
  }
  G = vvi(c);
  rep(i,N) {
    rep(j,N-2) {
      G[getId(i,A[i][j])].push_back(getId(i,A[i][j+1]));
    }
  }
  int ans = 0;
  rep(i,c) {
    int res = dfs(i);
    if(res==-1) {
      cout << -1 << endl;
      return 0;
    }
    chmax(ans,res);
  }
  cout << ans << endl;
  return 0;
}