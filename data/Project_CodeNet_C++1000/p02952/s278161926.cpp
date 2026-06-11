#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n, k, ans;
  ans = 0;
  cin >> n;
  k = n;
 
  while(k >= 100){
    k = k / 100;
    ans++;
  }
  
  if(ans == 0){
    cout << min(9,n);
  }
  else if(ans == 1){
    if(n >= 1000){
      cout << 909;
    }
    else{
      cout << 9 + n - 99;
    }
  }
  else{
    if(n >= 100000){
      cout << 90909;
    }
    else{
      cout << 909 + n - 9999;
    }
  }
 
  
  return 0;
}