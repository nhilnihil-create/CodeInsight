#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  ll h, n;
  cin >> h >> n;
  rep(i, n) {
    ll x;
    cin >> x;
    h -= x;
  }
  if (h > 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}