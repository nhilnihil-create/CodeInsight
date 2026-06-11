#include <bits/stdc++.h>
using namespace std;

int main() {
  string foo; cin >> foo;
  
  string ans = "No";
  if(foo.at(2) == foo.at(3) && foo.at(4) == foo.at(5)) {
    ans = "Yes";
  }
  cout << ans << endl;
  return 0; 
}