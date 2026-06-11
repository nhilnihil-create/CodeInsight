#include <iostream>

using namespace std;

int main() {
  unsigned long n, ac = 0, wa = 0, tle = 0, re = 0;
  cin >> n;
  string s[n];
  for (unsigned long i = 0; i < n; i++) {
    cin >> s[i];
    if (s[i] == "AC") ac++;
    else if (s[i] == "WA") wa++;
    else if (s[i] == "TLE") tle++;
    else if (s[i] == "RE") re++;
  }
  
  cout << "AC x " << ac << "\nWA x " << wa << "\nTLE x " << tle << "\nRE x " << re;
  
  return 0;
}