#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <sstream>
#include <fstream>
#include <climits>
#include <map>
#include <numeric>
#include <functional>
#include <utility>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;
typedef pair<int, int> P;

int main(void) {
  int k;
  cin >> k;
  string s;
  cin >> s;
  if (s.length() <= k) cout << s << endl;
  else cout << s.substr(0, k) << "..." << endl;

  return 0;
}
