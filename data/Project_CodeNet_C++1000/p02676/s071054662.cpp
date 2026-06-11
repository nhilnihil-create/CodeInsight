#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
  int k; string  s;
  cin >> k >> s;
  string res;
  if (s.size() > k) {
    string str(s.begin(), s.begin()+k);
    str += "...";
    res = str;
  } else {
    res = s;
  }
  cout << res << endl;

  return 0;
}

