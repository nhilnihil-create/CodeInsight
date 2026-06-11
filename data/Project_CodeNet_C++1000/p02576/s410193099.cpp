#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
  #include "_DEBUG.hpp"
#endif
#define int long long
const int INF = 1LL << 60;
const int MOD = 1e9 + 7;

signed main(){

  int n, x, t;
  cin >> n >> x >> t;
  
  if(n % x == 0){
    cout << t * (n / x) << endl;  
  }else{
    cout << (n / x) * t + t << endl;
  }

  return 0;
}