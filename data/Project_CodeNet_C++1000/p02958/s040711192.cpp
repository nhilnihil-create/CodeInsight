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
  int cnt = 0;
  rep(i,N) {
    int t;
    cin >> t;
    if (i+1 != t) ++cnt;
  }
  if (cnt == 0 || cnt == 2) {
    cout << "YES" << endl;
  }
  else cout << "NO" << endl;
  return 0;
}