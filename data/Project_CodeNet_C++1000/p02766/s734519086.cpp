#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  int k;
  cin >> k;

  ll current = n;
  ll ans = 0;
  while (current > 0) {
    current = current / k;
    ans++;
  }
  cout << ans << endl;
  return 0;
}