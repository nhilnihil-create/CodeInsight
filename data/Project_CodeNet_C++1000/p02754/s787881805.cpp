#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  ll n, a, b;
  cin >> n >> a >> b;
  if (a == 0) {
    cout << 0 << endl;
    return 0;
  }
  ll base = n / (a + b) * a;
  ll add = min(n % (a + b), a);
  cout << base + add << endl;
  
  
  return 0;
}