#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  ll a, v, b, w, t;
  cin >> a >> v >> b >> w >> t;
  if ((v - w) * t >= abs(a - b))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}