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
  int n;
  cin >> n;
  vector<int> vec(n);
  rep(i, n) cin >> vec.at(i);
  ll m = 1000;
  ll k = 0;
  rep(i, n) {
    if (i) {
      // sell
      if (vec.at(i-1) < vec.at(i)) {
        m += k * vec.at(i);
        k = 0;
      }
    }
    if (i != n - 1) {
      // buy
      if (vec.at(i+1) > vec.at(i)) {
        k += m / vec.at(i);
        m %= vec.at(i);
      }
    }
  }
  cout << m << endl;
  return 0;
}