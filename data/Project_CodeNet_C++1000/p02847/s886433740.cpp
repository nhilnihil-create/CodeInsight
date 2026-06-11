#include <bits/stdc++.h>

#define REP(i, x) for (int i = 0; i < (int)(x); i++)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  vector<string> wday = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  string S;
  cin >> S;
  auto it = find(wday.begin(), wday.end(), S);
  int d = distance(wday.begin(), it);
  cout << 7 - d << endl;

  return 0;
}
