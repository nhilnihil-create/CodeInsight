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
  int N;
  cin >> N;
  map<P, int> mp{};
  REP(i, N + 1) {
    if (i % 10 == 0) continue;
    P p;
    p.first = i % 10;
    string s = to_string(i);
    p.second = s[0] - '0';
    mp[p]++;
  }
  ll ans = 0;
  REP(i, N + 1) {
    P p;
    p.first = i % 10;
    string s = to_string(i);
    p.second = s[0] - '0';
    swap(p.first, p.second);
    ans += mp[p];
  }
  cout << ans << endl;
}