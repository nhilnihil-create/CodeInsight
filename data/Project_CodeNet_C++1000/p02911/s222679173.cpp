#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main() {
  int n,k,q;
  cin >> n >> k >> q;
  std::vector<int> a(n,k);
  rep(i,q) {
    int x;
    cin >> x;
    x--;
    a.at(x)++;
  }

  rep(i,n) {
    if (a.at(i) - q <= 0) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
}
