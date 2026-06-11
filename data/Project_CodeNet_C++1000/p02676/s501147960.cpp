#include <bits/stdc++.h>
using namespace std;
int main(void) {
  string s;
  long k;
  cin >> k >> s;
  if (s.size() <= k) {
    cout << s << endl;
  } else {
    cout << s.erase(k) << "..." << endl;
  }
  return 0;
}
