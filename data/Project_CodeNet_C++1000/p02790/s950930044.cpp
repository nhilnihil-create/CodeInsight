#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

string rec(int n, char s) {
  if (n == 0) {
    return "";
  }
  string a = rec(n-1, s);
  return a + s;
}

int main()
{
  int a, b;
  cin >> a >> b;
  char ca = a + '0';
  char cb = b + '0';
  string pow_a = rec(b, ca);
  string pow_b = rec(a, cb);
  cout << min(pow_a, pow_b) << endl;
  
  return 0;
}