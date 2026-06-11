#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  vector<string> day = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  string S;
  cin >> S;
  rep(i, 7) {
    if (day[i] == S) {
      cout << 7 - i << '\n';
      return 0;
    }
  }
  return 0;
}