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
  int n;
  cin >> n;
  string ans;
  switch (n % 10)
  {
  case 2:
  case 4:
  case 5:
  case 7:
  case 9:
    ans = "hon";
    break;
  case 0:
  case 1:
  case 6:
  case 8:
    ans = "pon";
    break;
  case 3:
    ans = "bon";
    break;
  default:
    break;
  }
  cout << ans << endl;

  return 0;
}
