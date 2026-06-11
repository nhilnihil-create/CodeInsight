#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const long long mod = 1e9+7;
//////////////////////////////////

int main() {
  string s; cin >> s;
  int n = s.size();
  for(int i=0; i<n; i++) {
    if (s[i] == '?') {
      s[i] = 'D';
    }
  }
  cout << s << endl;
  return 0;
}

// EOF