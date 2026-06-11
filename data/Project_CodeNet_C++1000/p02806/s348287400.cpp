#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  int N;
  cin >> N;
  vector<pair<string, int>> p(N);
  for (int i = 0; i < N; i++) {
    string a;
    int b;
    cin >> a >> b;
    p.at(i) = make_pair(a, b);
  }
  string X;
  cin >> X;

  bool flag = false;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    string a;
    int b;
    tie(a, b) = p.at(i);
    if (flag) ans += b;
    if (a == X) flag = true;
  }

  cout << ans << endl;
}