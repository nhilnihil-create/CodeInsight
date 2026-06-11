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
  int N, L;
  cin >> N >> L;
  int sum = 0;
  int eat = 9999999;
  rep(i,N) {
    int temp = L + i;
    if (abs(temp) < abs(eat)) eat = temp;
    sum += temp;
  }
  int ans = sum - eat;
  cout << ans << endl;
  return 0;
}