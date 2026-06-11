#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
map<string, int> m;
int main() {
  int x, y;
  cin >> x >> y;
  int ans = 0;
  if (x == 1 && y == 1)
    ans += 400000;
  if (x == 1)
    ans += 300000;
  else if (x == 2)
    ans += 200000;
  else if (x == 3)
    ans += 100000;
  if (y == 1)
    ans += 300000;
  else if (y == 2)
    ans += 200000;
  else if (y == 3)
    ans += 100000;
  cout << ans << endl;
}