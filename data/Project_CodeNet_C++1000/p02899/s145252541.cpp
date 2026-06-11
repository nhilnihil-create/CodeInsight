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
  vector<P> p(N);
  rep(i,N) {
    p[i].second = i + 1;
    cin >> p[i].first;
  }
  sort(p.begin(), p.end());
  rep(i,N) cout << p[i].second << " ";
  cout << endl;
  return 0;
}