#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  ll a, b, k;
  cin >> a >> b >> k;
  cout << max(0ll, a - k) << ' ' << max(0ll, min(b, a + b - k)) << endl;
  return 0;
}