#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair <int, int>;

int main() {
  int N;
  cin >> N;

  vector<pair<int, int>> ps(N);
  rep(i, N){
    int X, L;
    cin >> X >> L;
    ps.at(i) = make_pair(X+L, X-L);
  }

  sort(ps.begin(), ps.end());
  int cur = -1e9;
  int ans = 0;

  rep(i, N){
    if(cur <= ps.at(i).second){
      ans++;
      cur = ps.at(i).first;
    }
  }

  cout << ans << endl;
}
