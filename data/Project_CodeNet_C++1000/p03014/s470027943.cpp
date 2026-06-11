#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<int, int> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){

  ll h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h)cin >> s[i];

  vector<vector<ll>> L(h,vector<ll>(w));
  vector<vector<ll>> R(h,vector<ll>(w));
  vector<vector<ll>> U(h,vector<ll>(w));
  vector<vector<ll>> D(h,vector<ll>(w));

  rep(i,h)rep(j,w){
    if(s[i][j]=='#'){
      L[i][j]=0;
    }else if(j==0){
      L[i][j]=1;
    }else{
      L[i][j]=L[i][j-1]+1;
    }
  }

  rep(i,h){
    for(ll j = w-1; j >= 0;j--){
      if(s[i][j]=='#'){
        R[i][j]=0;
      }else if(j==w-1){
        R[i][j]=1;
      }else{
        R[i][j]=R[i][j+1]+1;
      }
    }
  }

  for(ll j = 0; j < w; j++){
    for(ll i = 0; i < h; i++){
      if(s[i][j]=='#'){
        U[i][j] = 0;
      }else if(i==0){
        U[i][j] = 1;
      }else{
        U[i][j] = U[i-1][j] +1;
      }
    }
  }

  for(ll j = 0; j < w; j++){
    for(ll i = h-1; i >= 0; i--){
      if(s[i][j]=='#'){
        D[i][j] = 0;
      }else if(i==h-1){
        D[i][j] = 1;
      }else{
        D[i][j] = D[i+1][j] +1;
      }
    }
  }

  ll ans = 0;
  rep(i,h)rep(j,w){
    ans = max(L[i][j]+R[i][j]+U[i][j]+D[i][j]-3, ans);
  }
  cout << ans << endl;


  // rep(i,h){
  //   rep(j,w){
  //     cout << U[i][j]<< " ";
  //   }
  //   cout << endl;
  // }


  return 0;
}