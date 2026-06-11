#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // greedy
  int N;
  cin >> N;
  vector<P> AB;
  rep(i, N) {
    int A, B;
    cin >> A >> B;
    AB.push_back(P(B, A));
  }
  sort(AB.begin(), AB.end());
  int cur = 0;
  rep(i, N) {
    cur += AB[i].second;
    if (cur > AB[i].first) {
      cout << "No" << '\n';
      return 0;
    }
  }
  cout << "Yes" << '\n';
  return 0;
}