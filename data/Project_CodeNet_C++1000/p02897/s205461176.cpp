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
  if (N%2 == 0) cout << fixed << setprecision(7) <<  0.5 << endl;
  else cout << fixed << setprecision(7) <<  (N+1)/(2.0*N) << endl;
  return 0;
}