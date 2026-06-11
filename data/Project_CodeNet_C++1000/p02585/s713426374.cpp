#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define reps(i,n) for (int i=1;i<=(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rreps(i,n) for (int i=(n);i>0;i--)
#define all(v) (v).begin(),(v).end()
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>
template<class T> inline bool chmin(T &a, T b) {if (a>b) {a = b; return 1;} return 0;};
template<class T> inline bool chmax(T &a, T b) {if (a<b) {a = b; return 1;} return 0;};
typedef long long int ll;
const long long INF = 1LL << 60;

void func1(int N, int K, int P[], ll C[]){
  bool checked[N] = {};
  vector<vector<ll>> group;
  rep(i,N){
    if (checked[i]) continue;

    int cur = i;
    vector<ll> tmp;
    while (!checked[cur]){
      checked[cur] = true;
      tmp.push_back(C[cur]);
      cur = P[cur];
    }
    group.push_back(tmp);
  }

  ll ans = -INF;
  for (auto vec : group){
    ll M = vec.size();
    ll acum[2*M+1]={};
    rep(i,2*M) acum[i+1] = acum[i] + vec[i%M];

    vector<ll> acum_max(M, -INF); // 連続するj(0<=j<=M-1)項の和の最大値
    rep(i,M) rep(j,M) chmax(acum_max[j], acum[i+j]-acum[i]);

    for (int r=0;r<M;r++){  // 始めのr項（余り）で最大化
      if (r>K) continue;
      ll q = (K-r)/M;
      if (r==0 && q==0) continue;

      if (acum[M]>0) chmax(ans, acum_max[r] + acum[M]*q);
      else if (r>0) chmax(ans, acum_max[r]);
    }

  }
  cout << ans << endl;
  return;
}

void func2(int N, int K, int P[], ll C[]){
  ll ans = -INF;
  
  rep(i,N){
    ll tmp = -INF, score = 0;
    int s = i;
    rep(j,K){
      s = P[s];
      score += C[s];
      chmax(tmp, score);
    }
    chmax(ans, tmp);
  }
  cout << ans << endl;
  return;
}

int main(){
  int N, K; cin >> N >> K;
  int P[N]; 
  rep(i,N) {
    int p; cin >> p;
    P[i] = p-1;
  }
  ll C[N]; rep(i,N) cin >> C[i];
  func1(N, K, P, C);
  // func2(N, K, P, C);
  

  // cout << fixed << setprecision(10);
  
  return 0;
}