#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  a--;
  ll y = a - (a / c) - (a / d) + (a / (lcm(c, d)));
  ll x = b - (b / c) - (b / d) + (b / (lcm(c, d)));
  cout << x - y << endl;
        

  return 0;
}