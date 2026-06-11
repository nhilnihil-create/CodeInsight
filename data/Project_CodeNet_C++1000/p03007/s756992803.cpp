#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int k;
  cin >> k;
  vector<int> pos, neg;

  rep(i,k) {
    int a;
    cin >> a;
    if (a < 0) neg.emplace_back(a);
    else pos.emplace_back(a);
  }

  sort(neg.begin(), neg.end());
  sort(pos.begin(), pos.end(), greater<int>());

  int n = neg.size(), m = pos.size();

  if (m == 0) {
    int res = neg[n-1];
    for (int i = 0; i < n-1; i++) {
      res -= neg[i];
    }
    cout << res << endl;
    for (int i = 0; i < n-1; i++) {
      cout << neg[n-1] << " " << neg[i] << endl;
      neg[n-1] -= neg[i];
    }
    return 0;
  }
  if (n == 0) {
    int res = pos[m-1];
    for (int i = m-2; i > 0; i--) {
      res -= pos[i];
    }
    res = pos[0] - res;
    cout << res << endl;
    for (int i = m-2; i > 0; i--) {
      cout << pos[m-1] << " " << pos[i] << endl;
      pos[m-1] -= pos[i];
    }
    cout << pos[0] << " " << pos[m-1] << endl;
    return 0;
  }

  int mx = pos[0], mi = neg[0];
  for (int i = 1; i < n; i++) {
    mx -= neg[i];
  }
  for (int i = 1; i < m; i++) {
    mi -= pos[i];
  }
  int res = mx - mi;
  cout << res << endl;
  for (int i = 1; i < n; i++) {
    cout << pos[0] << " " << neg[i] << endl;
    pos[0] -= neg[i];
  }
  for (int i = 1; i < m; i++) {
    cout << neg[0] << " " << pos[i] << endl;
    neg[0] -= pos[i];
  }
  cout << pos[0] << " " << neg[0] << endl;
  return 0;
} 