#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const long long mod = 1e9+7;
//////////////////////////////////

int main() {
  int n; cin >> n;
  vector<pair<int, int>> p(n);
  int x, l;
  for(int i=0; i<n; i++) {
    cin >> x >> l;
    p[i].first = x + l;
    p[i].second = x - l;
  }
  sort(all(p));
  int ans = 1;
  int pos = p[0].first;
  for(int i=1; i<n; i++) {
    if (pos <= p[i].second) {
      ans++;
      pos = p[i].first;
    }
  }
  cout << ans << endl;

  return 0;
}

// EOF