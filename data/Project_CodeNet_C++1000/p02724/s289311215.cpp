#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll x;
  cin >> x;
  ll fh = x / 500;
  ll f = (x % 500) / 5;
  cout << (fh * 1000) + f * 5 << endl;
}
