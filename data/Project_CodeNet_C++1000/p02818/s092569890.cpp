#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  ll a, b, k;
  cin >> a >> b >> k;
  ll aa = max((ll)0, a-k);
  ll r = max((ll)0, k-a);
  ll ab = max((ll)0, b-r);
  cout << aa << " " << ab << endl;

  return 0;
}