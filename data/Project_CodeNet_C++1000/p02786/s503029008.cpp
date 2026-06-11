#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll h;
  cin >> h;
  ll n = floor(log2(h));
  cout << fixed << setprecision(18) << (ll)pow(2,n+1)-1 << endl;
  return(0);
}