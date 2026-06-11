#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> d(1e5+1);
  rep(i,n) {
    int x;
    cin >> x;
    d[x]++;
  }
  int ans = 0;
  int sum = 0;
  for (int i = 1; i <= 1e5; i++) {
    sum += d[i];
    if (sum == n-sum) ans++;
  }
  cout << ans << endl;
  return 0;
}
