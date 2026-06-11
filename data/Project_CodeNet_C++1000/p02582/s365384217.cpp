#include <bits/stdc++.h>
using namespace std;

int main() {
  string in = "";
  char str;
  cin >> in;
  int ans = 0,count = 0;
  for (int i = 0; i < in.size(); i++) {
    str = in[i];
    if (str == 'R') {
      count++;
    }
    else if (count != 0) {
      ans = max(count, ans);
      count = 0;
    }
  }
  ans = max(count, ans);
  cout << ans << endl;
}
