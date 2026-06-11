#include <bits/stdc++.h>
#define ft first
#define sc second
#define pt(sth) cout << sth << "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
template<class T>bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=998244353;

//for(i=0; i<N; i++) cin >> a[i];



ll N, S;
ll a[3333];
ll dp[3333][6666];

int main(void) {
  ll i, j, k;
  
  cin >> N >> S;
  for(i=0; i<N; i++) cin >> a[i];
  
  dp[0][0]=1;
  for(i=0; i<N; i++) {
    for(j=0; j<=S; j++) {
      (dp[i+1][j]+=dp[i][j]*2)%=MOD;
      (dp[i+1][j+a[i]]+=dp[i][j])%=MOD;
    }
  }
  
  pt(dp[N][S]);
  
  
  
}
 
 


