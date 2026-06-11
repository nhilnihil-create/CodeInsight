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
  string S;
  ll K;
  cin >> S >> K;
  ll same = 0, tmp = 0;  //連続部分
  int k = 0;
  bool t = false, start = false;
  unordered_map<char, int> onaji{};
  onaji[S[0]]++;
  REP(i, S.size() - 1) {
    onaji[S[i]]++, onaji[S[i + 1]]++;
    if (S[i] == S[i + 1] && !t) {
      start = true;
      t = true;
      k = i;
    } else if (S[i] != S[i + 1] && start && t) {
      same += (i - k + 1);
      tmp += (i - k + 1) / 2;
      k = -1;
      t = false;
    }
  }
  if (t) {
    same += (S.size() - k);
    tmp += (S.size() - k) / 2;
  }
  string s = S;
  s.erase(unique(s.begin(), s.end()), s.end());
  if ( s.size() == 1) {
    cout << S.size() * K / 2 << endl;
    return 0;
  }
  if (S[0] != S[S.size() - 1]) {
    cout << tmp * K << endl;
    return 0;
  }
  ll a = 0, b = 0;
  char c = S[0];
  REP(i, S.size()) {
    if (S[i] == c) {
      a++;
    } else {
      break;
    }
  }
  c = S[S.size() - 1];
  REP(i, S.size()) {
    if (S[S.size() - 1 - i] == c) {
      b++;
    } else {
      break;
    }
  }
  cout << tmp * K - (K - 1) * (a / 2 + b / 2 - (a + b) / 2) << endl;
}