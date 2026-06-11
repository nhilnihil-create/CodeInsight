#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  string s, t, u;
  int a, b;
  cin >> s >> t >> a >> b >> u;
  if (u == s) {
    cout << a - 1 << " " << b << endl;
  } else if (u == t) {
    cout << a << " " << b-1 << endl;
  } else {
    cout << a << " " << b << endl;
  }
  
  return 0;
}