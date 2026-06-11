#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  cout << (4*a*b < (c-a-b)*(c-a-b) && c > a+b ? "Yes" : "No") << endl;
}
