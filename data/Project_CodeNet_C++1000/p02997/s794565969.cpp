#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define EPS (1e-9)
#define equals(a,b) (fabs((a)-(b))<EPS)

using namespace std;

bool LT(double a,double b) { return !equals(a,b) && a < b; }
bool LTE(double a,double b) { return equals(a,b) || a < b; }

const string YES = "";
const string NO  = "";

typedef long long ll;

void solve() {

}

#define MAX 110
vector<int> G[MAX];

int fw[MAX][MAX];
bool check(int N,int K) {
  rep(i,N) rep(j,N) fw[i][j] = INT_MAX;
  rep(i,N) fw[i][i] = 0;
  rep(i,N) {
    rep(j,(int)G[i].size()) {
      fw[i][G[i][j]] = 1;
      fw[G[i][j]][i] = 1;
    }
  }
  rep(k,N) rep(i,N) rep(j,N) {
    if( fw[i][k] == INT_MAX || fw[k][j] == INT_MAX ) continue;
    fw[i][j] = min(fw[i][j],fw[i][k]+fw[k][j]);
  }
  int cnt = 0;
  rep(i,N) {
    REP(j,i+1,N) {
      if( fw[i][j] == 2 ) ++cnt;
    }
  }
  //cout << "cnt = " << cnt << ", K = " << K << endl;
  return cnt == K;
}

int main() {
  int N,K;
  cin >> N >> K;
  /*
  if( K < N - 2 ) {
    puts("-1");
    return 0;
  }
  if( N > 2 && N == K ) {
    cout << N << endl;
    rep(i,N) {
      int s = i, t = ( i + 1 ) % N;
      cout << s + 1 << " " << t + 1 << endl;
    }
    return 0;
  }
  */
  int n = N - 1;
  /*
  if( K > (int)(n*(n-1)/2) ) {
    puts("-1");
    return 0;
  }
  */
  REP(i,1,N) {
    G[0].pb(i);
  }
  typedef pair<int,int> ii;
  int sum = n * (n-1) / 2;
  int diff = sum - K;
  REP(i,1,N) {
    REP(j,i+1,N) {
      if( diff <= 0 ) break;
      G[i].pb(j);
      --diff;
    }
    if( diff <= 0 ) break;
  }

  
  set<ii> S;
  rep(i,N) {
    rep(j,(int)G[i].size()) {
      if( i < G[i][j]) {
	S.insert(ii(i,G[i][j]));
      }
    }
  }

  if( !check(N,K) ) {
    puts("-1");
    return 0;
  }
  
  cout << S.size() << endl;
  for(auto v : S) {
    cout << v.fst + 1 << " " << v.snd + 1 << endl;
  }


  
  return 0;
}
