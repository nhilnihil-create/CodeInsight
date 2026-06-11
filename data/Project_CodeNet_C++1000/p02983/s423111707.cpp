#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  ll L, R;
  cin >> L >> R;
  if (2500 <= R - L) {
    cout << 0 << endl;
    return 0;
  }
  vector<ll> A(0);
  for (int i = L; i <= R; i++) {
    A.push_back(i % 2019);
  }
  ll mn = INF;
  REP(i, A.size() - 1) {
    for (ll j = i + 1; j < A.size(); j++){
      mn = min(mn, A[i]*A[j]%2019);
    }
  }
  cout << mn << endl;
}