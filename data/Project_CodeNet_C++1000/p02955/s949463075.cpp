#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
#define PI 3.141592653589793
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}
int gcd(int a, int b){//ユークリッドの互除法
  if (a < b) gcd(b,a); //aの方がbよりでかいのが前提
  if (b == 0) return a; //aをbで割り切れたらreturn
  else gcd(b, a % b);
}
const int INF = 1<<30;
const int MOD = 1000000007;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main(){
  int n,k; cin >> n >> k;
  vector<int> a(n);
  ll sum = 0;
  rep(i,n) cin >> a[i],sum += a[i];
  set<ll> candidates;
  for(int i = 1; i*i <= sum; i++){
    if(sum%i == 0){
      candidates.insert(i);
      candidates.insert(sum/i);
    }
  }
  
  ll ans = 1;
  
  for(ll x:candidates){
    ll need = 1LL << 60;
    vector<ll> r(n);
    rep(i,n) r[i] = a[i]%x;
    sort(r.begin(),r.end());
    ll B = 0;
    rep(i,n) B += x-r[i];
    ll A = 0;
    rep(i,n){
      A += r[i];
      B -= x-r[i];
      need = min(need, max(A,B));
    }
    if(need <= k) chmax(ans,x);
  }
  cout << ans << endl;
  
  return 0;
}