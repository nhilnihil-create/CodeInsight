#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
//using ll = long long;
//using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  vector<string> a(3);
  a[0] = "Sunny";
  a[1] = "Cloudy";
  a[2] = "Rainy";
  rep(i,3) {
    if (s == a[i]) cout << a[(i+1)%3] << endl;
  }
  return 0;
}