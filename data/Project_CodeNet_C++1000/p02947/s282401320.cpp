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
  vector<string> s(N);
  unordered_map<string, ll> mp{};
  REP(i, N) {
    cin >> s[i];
    sort(s[i].begin(), s[i].end());
    mp[s[i]]++;
  }
  ll ans = 0;
  REP(i, s.size()) {
    mp[s[i]]--;
    ans += mp[s[i]];
  }
  cout << ans << endl;
}