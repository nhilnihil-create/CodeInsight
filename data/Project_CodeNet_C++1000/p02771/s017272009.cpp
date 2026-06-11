#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  if (a == b && a == c && c == b) {
    cout << "No" << endl;
    return 0;
  }

  if (a == b || a == c || c == b) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}