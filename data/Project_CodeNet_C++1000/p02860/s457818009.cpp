#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)

int main() {
  int n;
  string s;
  cin >> n >> s;
  string t = s.substr(0,s.size()/2);
  if (n % 2 == 0 && t == s.substr(s.size()/2, s.size())) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
