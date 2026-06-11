#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  int s = 0;
  rep(i, n) {
    cin >> a[i];
    s += a[i];
  }
  int ans = 0;
  rep(i, n) {
    if(a[i] * 4 * m >= s) {
      ans++;
    }
  }
  if(ans >= m)
    cout << "Yes";
  else
    cout << "No";
}
