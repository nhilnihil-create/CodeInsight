// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

int main() {
  ll n; cin >> n;
  ll s = 100;
  int y=0;
  while (s < n) {
    s += (s/100);
    y++;
  }
  cout << y << endl;
  return 0;
}
