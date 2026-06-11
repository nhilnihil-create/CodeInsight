#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  if (s[2] == s[3] && s[4] == s[5])
    cout << "Yes\n";
  else
    cout << "No\n";
}
