#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int sum = 0;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'R') {
      sum++;
      ans = max(ans, sum);
    }
    else sum = 0;
  }
  
  cout << ans;
}