#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  string T;
  cin >> T;
  string ans;
  rep(i, N) {
    ans.push_back(S[i]);
    ans.push_back(T[i]);
  }
  cout << ans << '\n';
  return 0;
}