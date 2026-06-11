#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { return a * b / gcd(a, b); }

int main()
{
  int n;
  cin >> n;
  vector<int> vec(n);
  rep(i, n) {
    cin >> vec[i];
  }
  int b = vec[0];
  for(int i = 1; i < n; i++) {
    b = lcm(b, vec[i]);
  }
  int d = 0;
  rep(i, n) {
    d += b / vec[i];
  }
  double c = d * 1.0;
  printf("%.8f", b / c);
  return 0;
}