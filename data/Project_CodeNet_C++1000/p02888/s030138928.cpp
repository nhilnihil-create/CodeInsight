#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  int n; cin >> n;
  vector<int> L(n);
  rep(i,n) cin >> L[i];
  
  sort(L.begin(), L.end());
  int ans = 0;
  for(int i=0; i<n-2; i++){
    for(int j=i+1; j<n-1; j++){
      int k = lower_bound(L.begin(), L.end(), L[i] + L[j]) - L.begin();
      ans += max(k - (j+1), 0);
    }
  }
  
  cout << ans << endl;
}