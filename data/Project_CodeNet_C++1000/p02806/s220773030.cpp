#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
typedef long long ll;
using namespace std;
 
int main(void) {
  int n;
  cin >> n;
  string s[n];
  int t[n];
  int ans = 0;
  for(int i = 0; i < n; i++) {
    cin >> s[i] >> t[i];
    ans += t[i];
  }
  string x;
  cin >> x;
  for(int i = 0; i < n; i++) {
    ans -= t[i];
    if(s[i] == x)
      break;
  }
 
  cout << ans << endl;
 
  return 0;
}