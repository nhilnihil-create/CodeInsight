#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = a; i < (b + a); i++)
#define W1 while (1)
#define COUT(x) cout << x << endl
using namespace std;
using ll = long long;
using ld = long double;
#define ALL(x) x.begin(),x.end()
#define P pair<int,int>
#define mod 1000000007
#define PB push_back
#define F first
#define S second

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  int count = 0;
  while (a >= b) {
    count++;
    b *= 2;
  }
  while (b >= c) {
    count++;
    c *= 2;
  }
  if (count <= k) COUT("Yes");
  else COUT("No");

  return 0;
}
