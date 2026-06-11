#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a.at(i);
  
  long long cnt = 0;
  const long long mod = pow(10,9) + 7;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      if(a.at(i) > a.at(j)) cnt++;
    }
  }
  long long ans = (cnt * k) % mod;
  
  cnt = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(a.at(i) > a.at(j)) cnt++;
    }
  }
  ans += (k * (k-1) / 2) % mod * cnt % mod;
  ans %= mod;
  
  cout << ans << endl;
}