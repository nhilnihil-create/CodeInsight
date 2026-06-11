#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  std::vector<int> a(n);
  std::vector<int> b(n);
  std::vector<int> c(n-1);
  rep(i,n) {
    int x;
    cin >> x;
    x--;
    a.at(i) = x;
  }
  int total = 0;
  rep(i,n) {
    cin >> b.at(i);
    total += b.at(i);
  }
  rep(i,n-1) cin >> c.at(i);

  rep(i,n-1) {
    if (a.at(i)+1 == a.at(i+1)) {
      total += c.at(a.at(i));
    }
  }
  cout << total << endl;
}
