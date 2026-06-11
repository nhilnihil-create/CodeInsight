#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n, sum = 0;
  cin >> n;
  vector<int> vec(n);
  rep(i, n) {
    cin >> vec.at(i);
  }
  for(int i = 0; i < n - 1; i++) {
    for(int j = i + 1; j < n; j++) {
      sum += vec.at(i) * vec.at(j);
    }
  }
  cout << sum << endl;
}
