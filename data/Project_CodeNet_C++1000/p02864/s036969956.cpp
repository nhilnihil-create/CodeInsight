#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
#define PI 3.141592653589793
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}
int gcd(int a, int b){//ユークリッドの互除法
  if (a < b) gcd(b,a); //aの方がbよりでかいのが前提
  if (b == 0) return a; //aをbで割り切れたらreturn
  else gcd(b, a % b);
}

const int MAX = 1000000;
const int MOD = 1000000007;
const ll INF = 1LL << 60;

ll dp[305][305];

int main(){
  int n,k; cin >> n >> k;
  int m = n-k;//残す数
  vector<int> h(n);
  rep(i,n) cin >> h[i];
  h.insert(h.begin(),0);
  rep(i,n+1)rep(j,m+1) dp[i][j] = INF;
  dp[0][0] = 0;
  
  for(int i = 1; i <= n ;i++)rep(j,m){
    ll now = INF;
    rep(k,i){
      chmin(now, dp[k][j]+max(0,h[i]-h[k]));
    }
    dp[i][j+1] = now;
  }
  
  ll ans = INF;
  rep(i,n+1) chmin(ans, dp[i][m]);
  cout << ans << endl;
  
  return 0;
}