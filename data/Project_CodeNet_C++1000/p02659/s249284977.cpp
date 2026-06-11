#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
  ll a;
  string b;
  cin >> a >> b;
  ll b_sub = (b[0] - '0') * 100 + (b[2] - '0') * 10 + (b[3] - '0');
  cout << a * b_sub / 100 << endl;
}
