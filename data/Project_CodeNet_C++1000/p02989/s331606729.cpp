#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;cin>>N;
  vector<ll> d(N);rep(i,N) cin>>d[i];
  
  sort(d.begin(),d.end());
  ll ans=d[N/2]-d[N/2-1];
  
  cout << ans << endl;
}
