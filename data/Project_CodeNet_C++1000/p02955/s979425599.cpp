#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long
const int INF = 1LL << 60;

signed main(){

  int n, k; cin >> n >> k;
  vector<int> a(n);
  int sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
  }

  vector<int> vec;
  for(int i = 1; i <= sqrt(sum); i++){
    if(sum % i == 0){
      vec.push_back(i);
      vec.push_back(sum / i);
    }
  }

  int ans = 0;
  for(int p : vec){
    auto v = a;
    for(int i = 0; i < n; i++){
      v[i] = a[i] % p;
    }
    sort(v.begin(),v.end());
    vector<int> left(n+1, v[0]), right(n+1, 0);
    for(int i = 1; i < n; i++){
      left[i] = left[i-1] + v[i];
    }
    for(int i = n-1; i >= 0; i--){
      right[i] = right[i+1] + p - v[i];
    }
    for(int i = 1; i <= n; i++){
      if(left[i-1] == right[i] && max(left[i-1], right[i]) <= k){
        ans = max(ans, p);
      }
    }
  }
  cout << ans << endl;

  return 0;
}
