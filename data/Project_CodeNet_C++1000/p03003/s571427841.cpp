#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = ll(A); I < ll(B); ++I)
#define FORR(I,A,B) for(ll I = ll((B)-1); I >= ll(A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //xi>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //xi>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define REV(x) (reverse(x.begin(),x.end())) //reverse
//ll gcd(ll a,ll b){if(a%b==0)return b;return gcd(b,a%b);}
//ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=ll(1e16)+ll(7);
const ll MOD=1000000007LL;
#define out(a) cout<<fixed<<setprecision((a))
//tie(a,b,c) = make_tuple(10,9,87);
#define pop_(a) __builtin_popcount((a))
ll keta(ll a){ll r=0;while(a){a/=10;r++;}return r;}
ll ketawa(ll a){ll r=0;while(a){r+=a%10;a/=10;}return r;}


int main(){

  int n,m;
  cin >> n >> m;

  vector< vector<ll> > dp(n+1,vector<ll>(m+1,0));
  vector<ll> s(n),t(m);

  /*
    2dimBITを使えば
    cnt[i][j] := sのi文字目とtのj文字目が最後になるときの個数
    とすると
    s[i]==t[j]:
      cnt[i][j] = sum(cnt[x][y]|x<i,y<j) + 1;
    s[i]!=t[j]:
      cnt[i][j] = 0;
    とするとO(NM(logNlogM))でできる
    ans = sum(cnt)


    dp[i][j] := sはi文字目までtはj文字目まで見た時の個数
    ans = dp[n][m]
    2dimBITの時はans=sum(cnt)だった。今回はdp[i][j]をdp[n][m]まで伝搬させてる？？
    dp[i+1][j+1] = (伝搬されてきたやつ) + (sのi文字目とtのj文字目が最後になるときの個数)
    (伝搬されてきたやつ) = dp[i+1][j] + dp[i][j+1] - dp[i][j]
    (sのi文字目とtのj文字目が最後になるときの個数) = dp[i][j]
    O(NM)

    s[i]!=t[j]の時:
      dp[i+1][j+1] = dp[i+1][j]+dp[i][j+1]-dp[i][j];
    s[i]==t[j]の時:
      dp[i+1][j+1] = dp[i+1][j]+dp[i][j+1];
  */

  for(auto &&x:s)cin>>x;
  for(auto &&x:t)cin>>x;
  for(int i=0;i<n+1;i++)dp[i][0] = 1;
  for(int j=0;j<m+1;j++)dp[0][j] = 1;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      dp[i+1][j+1] += dp[i][j+1];
      dp[i+1][j+1] += dp[i+1][j];
      if(s[i]!=t[j]){
        dp[i+1][j+1] += MOD - dp[i][j];
      }
      dp[i+1][j+1] %= MOD;
    }
  }
  cout << dp[n][m] << endl;
}
