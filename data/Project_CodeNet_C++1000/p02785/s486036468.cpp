#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main() {
  int n,k;
  cin >> n >> k;
  std::vector<int> vec(n);
  rep(i,n) cin >> vec.at(i);
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  ll total = 0;
  rep(i,n) {
    if (i < k) continue;
    total += vec.at(i);
  }
  cout << total << endl;
}
