#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int main(){
  long long n, k; cin >> n >> k;
  vector<int> v(n);
  for(int i = 0; i < n; ++i) cin >> v[i];
  long long ans = 0;
  for(int i = 0; i < n; ++i){
    for(int j = i + 1; j < n; ++j){
      if(v[i] == v[j]) continue;
      if(v[i] > v[j]) ans += (k * (k + 1) / 2) % mod;
      else ans += (k * (k - 1) / 2) % mod; 
      ans %= mod;
    }
  }
  cout << ans << endl;
}