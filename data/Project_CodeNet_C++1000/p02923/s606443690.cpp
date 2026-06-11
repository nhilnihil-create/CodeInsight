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
  int N;
  cin >> N;
  vector<int> H(N);
  rep(i,N) cin >> H[i];
  int ans = 0;
  int temp = 0;
  rep(i,N-1) {
    if (H[i] >= H[i+1]) ++temp;
    else {
      ans = max(ans, temp);
      temp = 0;
    }
  }
  ans = max(ans, temp);
  cout << ans << endl;
  return 0;
}