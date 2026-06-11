#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  bool ans = false;
  cin >> s;
  for(int i = 0; i < 3; i++){
    if(s[i] == '7') {
      ans = true;
    }
  }
  if(ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
