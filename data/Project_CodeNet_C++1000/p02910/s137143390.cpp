// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

int main() {
  string s; cin >> s;
  int n = s.size();
  for (int i=0; i<n; i+=2) {
    if (s[i] == 'L') {
      cout << "No" << endl;
      return 0;
    }
  }
  for (int i=1; i<n; i+=2) {
    if (s[i] == 'R') {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
