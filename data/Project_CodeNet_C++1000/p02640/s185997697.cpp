#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if (b%2) {
    cout << "No" << endl;
    return 0;
  }
  int low = a*2, h = a*4;
  if (low <= b && b <= h)
    cout << "Yes" << endl;
  else  cout << "No" << endl;
  return 0;
}
