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
  vector<int> H(N);
  rep(i,N) cin >> H[i];
  int temp = 1000000005;
  for (int i = N-1; i > 0; --i) {
    if (temp >= H[i]) temp = H[i];
    else if (temp == H[i] - 1) continue;
    else {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}