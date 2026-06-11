#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  ll x;
  cin >> x;
  for(ll i = -1000; i < 1001; i++) {
    for(ll j = -1000; j < 1001; j++) {
      if (pow(i, 5) - pow(j, 5) == x) {
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
  return 0;
}