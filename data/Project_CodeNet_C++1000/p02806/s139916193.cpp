#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<string, int>> inp(n);
  for (auto&pa : inp) cin >> pa.first >> pa.second;
  string sleep;
  cin >> sleep;
  int acc = 0;
  for (auto&pa : inp) {
    acc += pa.second;
    if (pa.first == sleep) {
      acc = 0;
    }
  }
  cout << acc << endl;
}
