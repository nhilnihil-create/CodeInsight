#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (long long)n; i++)
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Vecl = vector<ll>;
using Graph = vector<vector<int>>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string S;
  cin >> S;
  if (S.size() % 2 == 1) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < S.size(); i++) {
    if (i % 2 == 0) {
      if (S.at(i) != 'h') {
        cout << "No" << endl;
        return 0;
      }
    } else {
      if (S.at(i) != 'i') {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}