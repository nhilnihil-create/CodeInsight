#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  ll x;
  cin >> x;
  if (x % 100 == 0) {
    cout << 1 << endl;
    return 0;
  }
  int s = x / 100;
  int r = x - s * 100;
  if (r <= s*5) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}