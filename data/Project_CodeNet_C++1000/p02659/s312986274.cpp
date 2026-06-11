#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main()
{
  // ll a;
  // string b, bb;
  // cin >> a >> b;
  // b = b.erase(1, 1);
  // a = a * stoi(b) / 100;
  ll a;
  double b;
  cin >> a >> b;
  ll bb = b * 100 + 0.5;
  a *= bb;
  a /= 100;
  cout << a;
}
