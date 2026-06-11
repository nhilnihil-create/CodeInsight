#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<iomanip>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

const int MAX = 5100;
const int MOD = 998244353;

ll dp[2][MAX];
// 和について何通りの選び方があるのか保存しとく

int main(){
  ll N , S; cin >> N >> S;
  vector<ll> a(N); rep(i,N) cin >> a[i];
  ll ans = 1;
  dp[0][0] = 1;
  rep(i,N){
    // 選ばない場合
    rep(j,S + 1){
      dp[1][j] = 2 * dp[0][j];
      dp[1][j] %= MOD;
    }
     // 選ぶ場合
     rep(j,S + 1){
       if(j + a[i] > S) continue;
       else{
         dp[1][j + a[i]] += dp[0][j];
         dp[1][j + a[i]] %= MOD;
       }
     }
     // 入れ替え
     rep(j , S + 1){
       dp[0][j] = dp[1][j];
     }
  }
  // rep(i,S) cout << i << " " << dp[0][i] << endl;
  cout << dp[0][S] << endl;
}
