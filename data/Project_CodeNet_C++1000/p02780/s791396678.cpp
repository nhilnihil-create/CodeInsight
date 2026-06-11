#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N,K;
  cin >> N >> K;
  vector<double> E(N);
  for(ll i=0;i<N;i++){
    ll p;
    cin >> p;
    E[i]=((double)p+1.0)/2.0;
  }
  double ans=0;
  for(ll i=0;i<K;i++){
    ans+=E[i];
  }
  double current=ans;
  for(ll i=1;i<N-K+1;i++){
    current = current -E[i-1]+E[i+K-1];
    ans=max(ans,current);
  }
  cout << fixed << setprecision(10);
  cout << ans << endl;
}