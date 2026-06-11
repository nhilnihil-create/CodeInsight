#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  int k;
  string s;
  cin >> k >> s;
  int n = s.size();
  if (n <= k) {
    cout << s << endl;
  } else {
    cout << s.substr(0, k) << "..." << endl;
  }
  return 0;
}