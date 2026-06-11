#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int digit(int x) {
  int d = 0;
  while (x > 0) {
    x /= 10;
    ++d;
  }
  return d; 
}

int main() {
  int N;
  cin >> N;
  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    if (digit(i)%2==1) ++ans;
  }
  cout << ans << endl;
  return 0;
}