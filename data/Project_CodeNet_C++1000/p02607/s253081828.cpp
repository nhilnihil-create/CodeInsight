#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int> a(n+1);
  rep(i,n) cin >> a[i];
  int ans = 0;
  rep(i,n) if(i % 2 == 1 && a[i] % 2 == 1) ans++;
  cout << ans << endl;
}