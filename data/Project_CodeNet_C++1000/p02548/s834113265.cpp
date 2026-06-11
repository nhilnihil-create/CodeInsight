#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {

  ll n;
  cin >> n;

  ll ans = 0;

  for(ll i=1; i<n; ++i) {
    ll tmp = n/i;
    if(n%i==0) --tmp;
    ans += tmp;
  }

  cout << ans << endl;

  return 0;
}
