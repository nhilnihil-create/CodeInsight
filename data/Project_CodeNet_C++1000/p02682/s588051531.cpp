#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<math.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<n;i++)

int main()
{
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    if (k <= a) cout << k << "\n";
  else{
    if (k <= a + b) cout << a << "\n";
    else cout << a + a + b - k << "\n";
  }
    return 0;
}