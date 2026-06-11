#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N;
string S;

bool check(int x) {
  set<string> cand;
  for (int i = 0; i < N-2*x+1; i++) {
    cand.insert(S.substr(i, x));
    if (cand.count(S.substr(i+x, x))) {
      return true;
    }
  }
  return false;
}

int main() {
  // 二分探索、substr
  cin >> N;
  cin >> S;
  ll ok = 0; ll ng = (N / 2) + 1;
  while (abs(ng-ok) > 1) {
    ll mid = (ok+ng) / 2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << '\n';
  return 0;
}