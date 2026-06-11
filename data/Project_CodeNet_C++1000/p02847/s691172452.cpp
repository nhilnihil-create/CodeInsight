#include <bits/stdc++.h>

using namespace std;

#define ll long long

string s;

string days[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

void solve() {
  cin >> s;
  for (int i = 0; i < 7; i++) {
    if (s.compare(days[i])==0) {
      cout << (7-i) << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
