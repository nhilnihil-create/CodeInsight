#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
  ll S;
  cin >> S;
  ll v = pow(10, 9);
  ll t = sqrt(S);
  if (t * t == S) {
    cout << "0 0 " << t << " " << "0 0 " << t << "\n";
    return 0;
  }
  t += 1;
  ll e = t * t - S;
  cout << "0 0 " << t << " " << e << " " << "1 " << t << "\n";
  return 0;
}