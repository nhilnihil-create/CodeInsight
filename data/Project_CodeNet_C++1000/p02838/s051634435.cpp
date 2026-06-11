#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;


int main(){
  int n;
  cin >> n;
  ll a[n];
  rep(i,n)cin >> a[i];
  ll ans=0;
  rep(i,60){
    ll x=0;
    rep(g,n)if(a[g]>>i&1)++x;
    ll ans2=x*(n-x)%mod;//i桁目の1と0を数えて、(1,0)の組み合わせ数を出す(1,0の出る数は背反である)
    rep(g,i)ans2=ans2*2%mod;//オーバーフローを防ぐ為、repで2^iを計算している
    ans+=ans2;
    ans%=mod;
  }
  cout << ans << endl;
}