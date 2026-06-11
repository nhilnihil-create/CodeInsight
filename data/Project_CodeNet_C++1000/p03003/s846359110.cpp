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
  
int main() {
  int N,M;
  cin >> N >> M;
  vi s(N),t(M);
  rep(i,N) {
    cin >> s[i];
  }
  rep(i,M) {
    cin >> t[i];
  }
  vv(ll) sum(N,vl(M,0));
  drep(i,N) {
    drep(j,M) {
      if(j+1<M&&i+1<N) {
        sum[i][j] = MOD + sum[i+1][j] + sum[i][j+1] - sum[i+1][j+1];
      } else if(j+1<M) {
        sum[i][j] = sum[i][j+1];
      } else if(i+1<N) {
        sum[i][j] = sum[i+1][j];
      }
      sum[i][j] %= MOD;
      if(s[i] != t[j]) continue;
      ll k = 1;
      if(j+1<M&&i+1<N) {
        k += sum[i+1][j+1];
      }
      sum[i][j] += k;
      sum[i][j] %= MOD;
    }
  }
  cout << (sum[0][0]+1)%MOD << endl;
  return 0;
}