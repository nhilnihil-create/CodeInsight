#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  std::vector<int> vec(n);
  std::vector<int>a(n);
  rep(i,n) {
    int x;
    cin >> x;
    vec.at(i) = x;
    a.at(i) = x;
  }
  sort(a.begin(), a.end());
  int cnt = 0;
  rep(i,n) {
    if (a.at(i) != vec.at(i)) cnt++;
  }
  if (cnt <= 2) cout << "YES" << endl;
  else cout << "NO" << endl;
}
