#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  std::vector<int> d(n);
  rep(i,n) cin >> d.at(i);

  int total = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      total += d.at(i) * d.at(j);
    }
  }
  cout << total << endl;
}
