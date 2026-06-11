#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<pair<ll, ll>> z(N);
  for (int i = 0; i < N; i++) cin >> z[i].first >> z[i].second;
  sort(z.begin(),z.end());

  int ans = N+1;
  for(int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      ll p = z[j].first - z[i].first;
      ll q = z[j].second - z[i].second;
      cerr << "p=" << p << " q=" << q << endl;
      int cost = 1;
      for (int k = 0; k < N-1; k++) {
        bool ok = false;
        for (int l = k+1; l < N; l++) {
          if (z[l].first-z[k].first == p && z[l].second-z[k].second == q) {
            ok = true;
            break;            
          }
        }
        cerr << ok << endl;
        if (!ok) cost++;
      }
      cerr << "cost= " << cost << endl;
      ans = min(cost, ans);
    }
  }
  if (N == 1) ans = 1;
  cout << ans << endl;
  return 0;
}
