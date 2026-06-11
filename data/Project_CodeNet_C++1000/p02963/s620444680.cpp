#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
int main() {
  ll S;
  cin >> S;
  ll x = ll(1e9 - S % ((ll)1e9)) % (ll)1e9;
  ll y = (S + x) / 1e9;
  cout << fixed << "0 0 " << (ll)1e9 << " 1 " << x << " " << y << endl;
}