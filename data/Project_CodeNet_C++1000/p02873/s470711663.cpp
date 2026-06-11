#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* clang-format off */
#define INF (INT_MAX / 4)
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(a) (a).begin(), (a).end()
#define DEBUG(x) cout<<#x<<":"<<x<<"\n"
#define DEBUGS(v) cout << #v << ":";for(auto x:v){cout<<x<<" ";}cout<<"\n"
#define TIMER_S(start) chrono::system_clock::time_point start = chrono::system_clock::now();
#define TIMER_E(end) chrono::system_clock::time_point end = chrono::system_clock::now();
#define TIME(start, end) cout << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count()) << "ms" << "\n";
/* clang-format on */

int main() {
  string s;
  cin >> s;
  vector<ll> ans(s.size() + 1, 0);

  for (int i = 1; i <= s.size(); i++) {
    if (s.at(i - 1) == '<') {
      ans.at(i) = ans.at(i - 1) + 1;
    }
  }

  for (int i = s.size() - 1; i >= 0; i--) {
    if (s.at(i) == '>') {
      ans.at(i) = max(ans.at(i + 1) + 1, ans.at(i));
    }
  }

  ll answer = 0;
  for (auto x : ans) {
    answer += x;
  }
  //DEBUGS(ans);
  cout << answer << "\n";
}
