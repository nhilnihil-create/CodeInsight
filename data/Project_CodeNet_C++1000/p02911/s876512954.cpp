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
  int N, K, Q;
  cin >> N >> K >> Q;
  vector<int> score(N);
  rep(i,N) score[i] = K - Q;
  rep(i,Q) {
    int a;
    cin >> a;
    --a;
    ++score[a];
  }
  rep(i,N) {
    if (score[i] > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}