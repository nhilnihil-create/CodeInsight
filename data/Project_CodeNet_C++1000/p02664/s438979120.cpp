#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  string ans;
  for (char it:a) {
    if (it=='?') {
      ans+='D';
    }
    else {
      ans+=it;
    }
  }
  cout << ans;
  return 0;
}