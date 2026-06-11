#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n;
  cin >> n;
  int a[n];
  int b[3];
  int s;
  int ans = 0;
  rep(i, n) cin >> a[i];
  rep(i, n - 2) {
    b[0] = a[i];
    b[1] = a[i + 1];
    b[2] = a[i + 2];
    s = b[1];
    sort(b, b + 3);
    if (s == b[1]) ans++;
  }
  cout << ans << endl;
  return 0;
}