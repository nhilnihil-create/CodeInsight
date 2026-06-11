#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int n;
  cin >> n ;
  vector<ll> l(n);
  for(auto &x: l) cin >> x;
  int ans{};
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(l[i] == l[j]) continue;
      for(int k=j+1; k<n; k++){
        if(l[i] == l[k] || l[j] == l[k]) continue;

        int mx = max({l[i], l[j], l[k]});
        ll sm = l[i] + l[j] + l[k];
        if(mx < sm - mx) ans++;
      }
    }
  }
  cout << ans << endl;
}