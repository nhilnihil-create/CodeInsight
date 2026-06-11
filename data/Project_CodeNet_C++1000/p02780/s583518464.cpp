#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) {  a = b;  return true;  } return false; }


int main() {
  ll n,k; cin >> n >> k;
  vector<double> p(n);
  rep(i,n){
    double c; cin >> c;
    p[i] = (c+1)/2;
  }
  
  vector<double> sum(n+1,0);
  rep(i,n)  sum[i+1] += sum[i] + p[i];
  //累積和
  
  double ans = 0;
  for(ll i=k; i<n+1; i++) 
    ans = max(ans, sum[i]-sum[i-k]);
  
  printf("%.16f", ans);
}