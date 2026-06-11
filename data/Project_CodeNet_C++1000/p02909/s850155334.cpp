#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  string S;
  cin >> S;
  string ans;
  if (S == "Sunny") {
    ans = "Cloudy";

  } else if (S == "Cloudy") {
    ans = "Rainy";
  } else {
    ans = "Sunny";
  }
  cout << ans << endl;
  return 0;
}