
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
const ll INF = 10e9;
ll MOD=1000000007;

int main(){
  int n,m,x; cin>>n>>m>>x;
  int C[n];
  int A[n][m];
  ll algo[m];
  ll money = INF;
  bool jud = false;
  rep(i,n){
    cin>> C[i];
    rep(j,m) cin>>A[i][j];
  }
  rep(bit, 1<<n){
    rep(k,m) algo[k]=0;
    ll tmp = 0;
    rep(i,n){
      if (bit & (1<<i)){
        rep(j,m) algo[j] += A[i][j];
        tmp += C[i];
      }
    }
    bool ok = true;
    rep(k,m){
      if (algo[k]<x) ok = false;
    }
    if (ok){
      jud = true;
      money = min(money, tmp);
    }
  }
  if (jud) cout << money << endl;
  else cout << -1 << endl;
}