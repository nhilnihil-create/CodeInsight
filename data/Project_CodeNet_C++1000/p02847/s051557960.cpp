#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  vector<string> day = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  string s;
  cin >> s;
  int di = -1;
  rep(i, 7) if (day[i] == s) di = i;
  int ans = 7 - di;
  cout << ans << endl;
  return 0;
}