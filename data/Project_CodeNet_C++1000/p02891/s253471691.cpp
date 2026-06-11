#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (long long)n; i++)
//#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Vl = vector<ll>;
using vi = vector<int>;
using Graph = vector<vi>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(15); //"for float-base
  // problem"
  string S;
  int K;
  ll ans = 0;
  bool flag = false;
  cin >> S >> K;

  int left = 1, right = 1;
  for (int i = 0; i < S.size() - 1; i++) {
    if (S.at(i) != S.at(i + 1)) {
      flag = true;
      break;
    } else
      left++;
  }

  if (!flag) {
    cout << (S.size() * K) / 2 << endl;
    return 0;
  }

  for (int i = S.size() - 1; i > 0; i--) {
    if (S.at(i) != S.at(i - 1)) {
      break;
    } else
      right++;
  }

  for (int i = 0; i < S.size() - 1; i++) {
    if (S.at(i) == S.at(i + 1)) {
      S.at(i + 1) = '0';
      ans++;
    }
  }
  ans *= K;

  if (S.at(0) == S.at(S.size() - 1))
    ans -= ((left / 2) + (right / 2) - ((left + right) / 2)) * (K - 1);

  cout << ans << endl;
}
