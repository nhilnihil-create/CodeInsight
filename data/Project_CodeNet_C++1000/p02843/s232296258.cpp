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
  vector<int> vec(max(x+1, (ll)1e6+1), 0);
  rep(i, 6) {
    vec.at(i+100) = 1;
    rep(j, x+1) {
      if (i+j+100 > x) continue;

      if (vec.at(j)) vec.at(i+j+100) = 1;
    }
  }
  if (vec.at(x)) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}