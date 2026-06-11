#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N, K, amari, ans;
  cin >> N >> K;
  amari = N%K;
  if(amari < K-amari) ans = amari;
  else ans = K-amari;
  
  cout << ans << endl;
    
}