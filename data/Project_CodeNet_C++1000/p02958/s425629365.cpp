#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  rep(i, n) {
    cin >> vec.at(i);
  }
  auto vec2 = vec;
  sort(vec2.begin(), vec2.end());
  string ans = "NO";
  if (vec == vec2) ans = "YES";
  else {
    for(int i = 0; i < n-1; i++) {
      for(int j = i + 1; j < n; j++) {
        swap(vec.at(i), vec.at(j));
        if (vec == vec2) ans = "YES";
        else swap(vec.at(i), vec.at(j));
      }
    }
  }
  cout << ans << endl;
}