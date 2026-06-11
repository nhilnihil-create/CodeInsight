#include <bits/stdc++.h>
//#include "atcoder/all"
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
const ll mod = 1e9 + 7;
int main() {
  int n;
  cin >> n;
  vector<pii> d(n);

  for (int i = 0; i < n; i++) {
    cin >> d[i].first >> d[i].second;
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    if (d[i].first == d[i].second)
      count++;
    else
      count = 0;
    if (count >= 3) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}