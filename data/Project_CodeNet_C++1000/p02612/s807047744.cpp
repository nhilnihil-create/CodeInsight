#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  if(n%1000 == 0) cout << "0" << endl;
  else  {
    int t = n/1000 + 1;
    int ans = 1000 * t - n;
    cout << ans << endl;
  }
}
//18.1