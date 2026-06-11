//\\//\\ * * * //\\// ||
#include <bits/stdc++.h> 

#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int cur = 0;
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    cur *= 10;
    cur += 7;
    cur %= k;
    if (cur == 0) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}
