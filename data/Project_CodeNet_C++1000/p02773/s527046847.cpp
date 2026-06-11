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
  map<string,int> list;
  rep(i,N) {
    string S;
    cin >> S;
    list[S]++;
  }
  int m = 0;
  for (auto i = list.begin(); i != list.end(); ++i) {
    m = max(m, i->second);
  }
  for (auto i = list.begin(); i != list.end(); ++i) {
    if (i->second == m) cout << i->first << endl;
  }
  return 0;
}
