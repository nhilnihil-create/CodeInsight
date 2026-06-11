#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep_1(i, n) for (int(i) = 0; (i) <= (n); (i)++)
#define rep_2(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {
  vector<int> a(5);
  rep(i, 5) { cin >> a[i]; }
  rep(i, 5) {
    if (a[i] == 0) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  return 0;
}