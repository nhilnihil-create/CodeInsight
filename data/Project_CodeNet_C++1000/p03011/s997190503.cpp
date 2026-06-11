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
  int P, Q, R;
  cin >> P >> Q >> R;
  cout << min({P+Q, Q+R, R+P}) << endl;
  return 0;
}