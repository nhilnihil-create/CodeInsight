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
int main(){
  long long x;
  cin >> x;
  long long ans500;
  long long ans5;
  ans500 = x/500;
  x %= 500;
  ans5 = x/5;
  long long ans = 1000*ans500 + 5*ans5;
  cout << ans << endl;
}