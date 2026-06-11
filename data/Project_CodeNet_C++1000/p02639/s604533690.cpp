#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  vector<int> vec(5);
  rep(i,5) {
    cin >> vec.at(i);
  }
  int ans;
  rep(i,5) {
    if (vec.at(i) == 0) ans =  i + 1;
  }
  cout << ans;
}