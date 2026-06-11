#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  ll N, M, fin=0, mod=pow(10,9)+7, S=1;
  cin >> N >> M;
  vector<ll> a(M,0);
  set<ll> ss;
  for(ll i=0; i<M; i++) {
    cin >> a[i];
    ss.insert(a[i]);
  }
  for(ll i=0; i<M-1; i++) {
    if (a[i+1]-a[i]==1) {
      fin=1;
      break;
    }
  }
  //cout << fin << endl;
  if (fin==1) {
    cout << 0 << endl;
  }
  else {
    ll s=a.size();
    vector<int> dp(N+1);
    for (int x=0; x<=N; x++) {
      if (ss.count(x)) {dp[x]=0;}
      else if (x<2) {dp[x]=1;}
      else {
        ll d1=dp[x-1]+dp[x-2];
        dp[x]=d1-d1/mod*mod;
      }
    }
    cout << dp[N] << endl;
  }
}
