#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#define ll long long
#include <unordered_map>
using namespace std;
 
int main() {
  ll X, i = 0;
  cin >> X;
  while(1) {
    if(400 + 200 * i > X) {
      cout << 9 - i << endl;
      break;
    }
    i++;
  }
}