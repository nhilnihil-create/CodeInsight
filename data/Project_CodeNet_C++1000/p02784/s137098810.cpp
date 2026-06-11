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
  int H, N;
  cin >> H >> N;
  int sum = 0;
  rep(i,N) {
    int t;
    cin >> t;
    sum += t;
  }
  if (sum >= H) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}