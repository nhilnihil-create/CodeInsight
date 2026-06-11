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
  ll h;
  cin >> h;
  int r = log2(h);
  vector<ll> vec(100,-1);
  vec.at(0) = 1;
  ll ans = 1;
  reps(i, 1, r+1) {
    vec.at(i) = vec.at(i-1) * 2;
    ans += vec.at(i);
  }
  cout << ans << endl;
  return 0;
}