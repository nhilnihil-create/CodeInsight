#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  if(400<=n && n<=599) cout << 8 << endl;
  else if(600<=n && n<=799) cout << 7 << endl;
  else if(800<=n && n<=999) cout << 6 << endl;
  else if(1000<=n && n<=1199) cout << 5 << endl;
  else if(1200<=n && n<=1399) cout << 4 << endl;
  else if(1400<=n && n<=1599) cout << 3 << endl;
  else if(1600<=n && n<=1799) cout << 2 << endl;
  else if(1800<=n && n<=1999) cout << 1 << endl;
  return 0;
}