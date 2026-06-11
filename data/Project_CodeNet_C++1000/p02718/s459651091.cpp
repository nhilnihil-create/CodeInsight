#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;

signed main() {
  int n,m;
  cin >> n >> m;

  vector<int> a(n);
  int sum = 0;
  rep(i,n) {
    cin >> a[i];
    sum += a[i];
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int vote = a[i];
    if(vote * 4 * m < sum);
    else cnt++;
  }

  if(cnt >= m) cout << "Yes" << endl;
  else cout << "No" << endl;

}

