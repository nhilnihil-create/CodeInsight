#include <iostream>
typedef long long ll;
using namespace std;

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max(max(a * c, a * d), max(b * c, b * d)) << endl;
}