#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int gcd(int a, int b, int c) {
  int ans = 1;
  for (int i = 1; i <= min(min(a,b), c); ++i) {
    if (a % i == 0) {
      if (b % i == 0) {
        if (c % i == 0){
          ans = i;
        }
      }
    }
  }
  return ans;
}

int main() {
  int K;
  cin >> K;
  int ans = 0;
  for (int a = 1; a <= K; a++) {
    for (int b = 1; b <= K; b++) {
      for (int c = 1; c <= K; c++) {
        ans += gcd(a, b, c);
      }
    }
  }
  cout << ans << endl;
  return 0;
}