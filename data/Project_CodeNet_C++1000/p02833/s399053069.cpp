#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, ct=0;
  cin >> n;
  if(n%2==1){
    cout << 0;
    return 0;
  }
  n/=2;
  while(n>=1){
    ct+=n/5;
    n/=5;
  }
  cout << ct;
  return 0;
}