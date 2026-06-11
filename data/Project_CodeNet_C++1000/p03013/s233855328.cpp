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

int main(){
  int N, M; cin >> N >> M;

  vector<ll> dp(N+10,1);
  ll MOD = 1000000007;
  rep(i,M){
    int a; cin >> a;
    dp[a] = 0;
  }
  for (int i=1;i<=N;i++){
    if (dp[i]==0) continue;
    dp[i] = dp[i-1];
    if (i>1) dp[i] = (dp[i-1]+dp[i-2])%MOD;
  }
  cout << dp[N] << endl;

  // cout << fixed << setprecision(10);
  
  return 0;
}
