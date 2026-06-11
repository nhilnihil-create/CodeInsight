#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n,m,x; 
  cin >> n >> m >> x;
  
  vector<ll> C(n);
  vector<vector<ll>> A(n, vector<ll>(m));
  
  rep(i, n){
    cin >> C[i];
    rep(j, m)
      cin >> A[i][j];
  }
  
  ll ans, sum;
  rep(i, n)
    sum += C[i]; sum++;
  ans = sum;
   
  rep(i, 1<<n){
    ll cost = 0; vector<ll> a(m);
    rep(k, n){
      if((1<<k)&i) continue;
      rep(j, m) a[j] += A[k][j];
      cost += C[k];
      
      rep(j,m){
        if (a[j] < x) break;
        if (j == m - 1) ans = min(ans, cost);
      }
    }
  }
  if(ans == sum){
    cout << -1 << endl; return 0;}
  cout << ans << endl;
}