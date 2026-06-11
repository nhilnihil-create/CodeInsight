#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) { // n が 0 になるまで
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int fn(long long x, long long y, long long z){
  return x*x + y*y + z*z + x*y + y*z + z*x;
}
int main(){
  long long n;
  cin >> n;
  vector<long long> h(n);
  rep(i,n) cin >> h.at(i);
  int ans = 0;
  int num = 0;
  rep(i,n-1){
    if(h.at(i) >= h.at(i+1)) num++;
    else if(h.at(i) < h.at(i+1)) {
      if(ans < num ) ans = num;
      num = 0;
    }
  }
  if( ans < num) ans = num;
  cout << ans << endl;
}