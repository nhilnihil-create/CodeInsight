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

int main() {
  ll N;
  cin >> N;
  int M = 1000000;
  ll ans = 1000000000010;
  for (int i = 1; i <= M; ++i) {
    if (N%i==0) {
      ll temp = i + N/i;
      ans = min(ans, temp);
    }
  }
  cout << ans - 2 << endl;
  return 0;
}