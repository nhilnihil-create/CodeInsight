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
  vector<int> W(N);
  int sum = 0;
  rep(i,N) {
    cin >> W[i];
    sum += W[i];
  }
  int temp_sum = 0;
  int ans = 999999;
  rep(i,N) {
    temp_sum += W[i];
    sum -= W[i];
    ans = min(ans, abs(temp_sum - sum));
  }
  cout << ans << endl;
  return 0;
}