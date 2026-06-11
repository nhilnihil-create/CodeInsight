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
  double s = 0;
  rep(i, n) {
    int x;
    cin >> x;
    s += 1.0 / x;
  }
  printf("%.8f", 1.0 / s);
  return 0;
}