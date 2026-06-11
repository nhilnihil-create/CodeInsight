#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  vector<ll> vec(n);
  vector<ll> mvec(n);
  rep(i, n) {
    int x;
    cin >> x;
    vec[i] = x;
    mvec[i] = x;
  }
  sort(mvec.begin(), mvec.end());
  reverse(mvec.begin(), mvec.end());
  rep(i, n) {
    if (vec[i] == mvec[0]) {
      cout << mvec[1] << endl;
    } else {
      cout << mvec[0] << endl;
    }
  }
  return 0;
}