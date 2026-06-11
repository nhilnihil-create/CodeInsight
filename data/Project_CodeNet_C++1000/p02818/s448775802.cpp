 #include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  ll a, b, k;
  cin >> a >> b >> k;
  if(a >= k) {
    cout << a - k << " " << b << endl;
  }
  else if(a + b >= k) {
    cout << 0 << " " << b - (k - a) << endl;
  }
  else {
    cout << 0 << " " <<  0 << endl;
  }
  return 0;
}
  