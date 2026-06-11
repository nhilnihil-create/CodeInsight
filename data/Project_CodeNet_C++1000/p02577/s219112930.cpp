#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const long long mod = 1e9+7;
//////////////////////////////////

int main() {
  string s; cin >> s;
  int n = 0;
  for(int i=0; i<s.size(); i++) {
    n += s[i] - '0';
    n %= 9;
  }
  if (n == 0) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}

// EOF