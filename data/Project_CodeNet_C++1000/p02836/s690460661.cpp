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
  cin >> S;
  int l = 0, r = S.size() - 1, ans = 0;
  while (l < r) {
    if (S.at(l) != S.at(r)) ans++;
    l++;
    r--;
  }
  cout << ans << endl;
}