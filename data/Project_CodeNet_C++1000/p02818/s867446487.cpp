#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll a, b, k;
  cin >> a >> b >> k;
  cout << max((ll)0, a - k) << " " << 
    (a - k >= (ll)0 ? b : max((ll)0, a + b - k)) << endl;
}