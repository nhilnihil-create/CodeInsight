#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int cut = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'L' && i < n - 1 && s[i + 1] == 'R') {
      cut++;
    } else if(s[i] == 'R' && i < n - 1 && s[i + 1] == 'L') {
      cut++;
    }
  }
  cout << min(n - 1 - cut + k * 2, n - 1) << endl;
  return 0;
}