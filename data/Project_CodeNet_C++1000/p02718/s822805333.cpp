#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  int sum = 0;
  rep(i, n) {
    cin >> a.at(i);
    sum += a.at(i);
  }
  int cnt = 0;
  rep(i, n) {
    int tmp = sum / (4 * m);
    if(sum % (4 * m) != 0 && a.at(i) > tmp) cnt++;
    else if(sum % (4 * m) == 0 && a.at(i) >= tmp) cnt++;
  }
  if(cnt >= m) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
    