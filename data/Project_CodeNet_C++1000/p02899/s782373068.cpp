#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  std::vector<int> a(n);
  std::vector<int> b(n);
  rep(i,n) {
    int x;
    cin >> x;
    a.at(i) = x;
    b.at(i) = x;
  }
  sort(b.begin(), b.end());
  rep(i,n) {
    auto result = find(a.begin(), a.end(), b.at(i));
    std::size_t index = std::distance(a.begin(), result);
    cout << index + 1 << " ";
  }
  cout << endl;
}
