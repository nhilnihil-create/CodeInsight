#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,k;
  cin >> n >> k;

  int i;
  for(i = 0; n/k >= 1; i++) {
    n /= k;
  }
  cout << i+1 << endl;
}
