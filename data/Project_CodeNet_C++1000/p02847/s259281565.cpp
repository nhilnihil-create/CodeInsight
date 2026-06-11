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
  map<string, int> A {{"SUN", 0}, {"MON", 1}, {"TUE", 2}, {"WED", 3}, {"THU", 4}, {"FRI", 5}, {"SAT", 6}};
  string s;
  cin >> s;
  cout << 7 - A[s] << endl;
  return 0;
}