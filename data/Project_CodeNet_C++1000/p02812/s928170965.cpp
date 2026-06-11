#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  ll n, cnt = 0;
  string s;
  cin >> n >> s;
  rep(i, n) if (s.substr(i, 3) == "ABC") cnt++;
  cout << cnt << endl;
  return 0;
}
