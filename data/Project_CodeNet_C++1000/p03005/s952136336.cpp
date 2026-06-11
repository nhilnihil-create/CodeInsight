#include<bits/stdc++.h>
using namespace std;

int main(void) {
  int n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << 0 << endl;
    return 0;
  }
  int y = n - (k-1);
  int x = 1;
  cout << y -x << endl;
  return 0;
}
