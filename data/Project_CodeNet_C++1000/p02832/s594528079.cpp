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
  ll n;
  cin >> n;
  vector<ll> vec(n);
  for(int i = 0; i < n; i++) {
    cin >> vec.at(i);
  }
  ll cn = 1;
  ll cnt = 0;
  rep(i, n) {
    if (vec.at(i) == cn) {
      cnt++;
      cn++;
    }
  }
  if (cnt) {
    cout << n - cnt << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}