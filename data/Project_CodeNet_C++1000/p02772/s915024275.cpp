#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (int)n; i++)

const int inf = 1'000'000'000;

int main() {
  int n;
  cin >> n;
  std::vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x % 2 == 0) {
      vec.push_back(x);
    }
  }
  bool can = true;
  for (int i : vec) {
      if (i % 3 != 0 && i % 5 != 0) {
        can = false;
      }
  }
  if (can) cout << "APPROVED" << endl;
  else cout << "DENIED" << endl;
}
