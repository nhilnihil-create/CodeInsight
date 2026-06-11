#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int N;
  cin >> N;
  vector<int> A(N), plus(0), minus(0);

  REP(i, N) {
    cin >> A[i];
    if (A[i] < 0) {
      minus.push_back(A[i]);
    } else {
      plus.push_back(A[i]);
    }
  }
  sort(minus.begin(), minus.end());
  sort(plus.begin(), plus.end(), greater<int>());
  if (minus.empty()) minus.push_back(plus.back()), plus.pop_back();
  if (plus.empty()) plus.push_back(minus.back()), minus.pop_back();
  ll cur = minus[0];
  vector<P> Ans(0);
  for (int i = 0; i < plus.size() - 1; i++) {
    Ans.push_back(P(cur, plus[i]));
    cur -= plus[i];
  }
  Ans.push_back(P(plus.back(), cur));
  cur = plus.back()-cur;
  for (int i = 1; i < minus.size(); i++) {
    Ans.push_back(P(cur, minus[i]));
    cur -= minus[i];
  }
  cout << cur << endl;
  for (auto s : Ans) {
    cout << s.first << " " << s.second << endl;
  }
}