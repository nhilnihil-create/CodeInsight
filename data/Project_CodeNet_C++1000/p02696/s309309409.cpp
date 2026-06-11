#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main() {
  int a;
  ll b, n;
  cin >> a >> b >> n;

  ll x = min(b - 1, n);
  cout << a * x / b - a * (x / b);
}
